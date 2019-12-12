#include "addnewobjectdialog.h"
#include "ui_addnewobjectdialog.h"
#include <QFileDialog>
#include <QUrl>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "VideoDBContext.h"
#include "VideoRepository.h"
#include "FileException.h"
#include "QDialog"


QString ImageUrl;

AddNewObjectDialog::AddNewObjectDialog(MainWindow* mainWindow, QWidget *parent, QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>& actions) :
    QDialog(parent),
    ui(new Ui::AddNewObjectDialog),
    _mainWindow(mainWindow),
    _actions(&actions)
{
    ui->setupUi(this);
    SetDDLItems();

}

AddNewObjectDialog::~AddNewObjectDialog()
{
    delete ui;
}

void AddNewObjectDialog::SetDDLItems()
{
    ui->setCategoryComboBox->addItem("Melodram");
    ui->setCategoryComboBox->addItem("Drama");
    ui->setCategoryComboBox->addItem("Action");
    ui->setCategoryComboBox->addItem("Educational cartoon");
    ui->setCategoryComboBox->addItem("Anime");
}


void AddNewObjectDialog::on_openFileExplorerPushButton_clicked()
{
    QUrl filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", tr("Images (*.png *.xpm *.jpg)"));
    if (!filename.isEmpty())
    {
        QImage image(filename.toString());
        int w = image.width();
        int h = image.height();

        if (w >= 250 || h >= 250)
        {
            int diff = w - 250;

            w -= diff;
            h -= diff;
        }

        ui->imageContainer->setPixmap(QPixmap::fromImage(image).scaled(w, h, Qt::KeepAspectRatio));
    }

    ImageUrl = filename.toString();
}

void AddNewObjectDialog::on_addMoviePushButton_clicked()
{
    QString name = ui->setNameTextEdit->text();
    QString description = ui->setDescriptionTextEdit->toPlainText();
    QString category = ui->setCategoryComboBox->currentText();

    if (name.isEmpty())
    {
        ui->setNameTextEdit->setText("Name field cannot be empty!");
        ui->setNameTextEdit->setStyleSheet("QLineEdit {color: red;}");
    }

    if (description.isEmpty())
    {
        ui->setDescriptionTextEdit->setText("Sescription field cannot be empty!");
        ui->setDescriptionTextEdit->setStyleSheet("QTextEdit {color: red;}");
    }

    if (ImageUrl.isEmpty())
    {
        ui->openFileExplorerPushButton->setText("Image field cannot be empty!");
        ui->openFileExplorerPushButton->setStyleSheet("QPushButton {color: red;}");
    }

    else
    {
        QString date = QDate::currentDate().toString("dd.MM.yyyy");
        VideoDBContext dbContext(category, name, description, ImageUrl, date);
        VideoRepository repos;
        try
        {
            repos.Add(dbContext);
        }
        catch(const FileException& ex)
        {
            QDialog* dialog = new QDialog();
            dialog->setModal(true);
            QHBoxLayout* layout = new QHBoxLayout();
            QLabel* lab = new QLabel();
            lab->setText(ex.ExceptionDescription+ "  " + ex.FileName + " " + ex.ExceptionCode);
            layout->addWidget(lab);
            dialog->setLayout(layout);
            dialog->exec();
            return;
        }


        this->_actions->append(qMakePair(ActionEnum::ADD, qMakePair(repos.GetLastId(), dbContext)));
        this->close();
    }

    VideoRepository repos;
    QMap<int, VideoDBContext> dbContextMap;
    try
    {
        dbContextMap = repos.GetAll();
    }
    catch(const FileException& ex)
    {
        QDialog* dialog = new QDialog();
        dialog->setModal(true);
        QHBoxLayout* layout = new QHBoxLayout();
        QLabel* lab = new QLabel();
        lab->setText(ex.ExceptionDescription+ "  " + ex.FileName + " " + ex.ExceptionCode);
        layout->addWidget(lab);
        dialog->setLayout(layout);
        dialog->exec();
        return;
    }

    this->_mainWindow->SetUpScrollArea(dbContextMap);
}

void AddNewObjectDialog::on_cancelPushButton_clicked()
{
    this->close();
}

void AddNewObjectDialog::on_setDescriptionTextEdit_textChanged()
{
    ui->setDescriptionTextEdit->setStyleSheet("QLineEdit {color: black;}");
}

void AddNewObjectDialog::on_setNameTextEdit_textChanged(const QString &arg1)
{
    ui->setNameTextEdit->setStyleSheet("QTextEdit {color: black;}");
}
