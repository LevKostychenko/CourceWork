#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewobjectdialog.h"
#include <QLabel>
#include <QTimer>
#include <QMap>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPixmap>
#include <QString>
#include "VideoDBContext.h"
#include "video.h"
#include "VideoRepository.h"
#include "filmblock.h"
#include "qdebug.h"
#include "FindLogic.h"
#include "FileException.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    }
    SetDDLItems();
    SetUpScrollArea(dbContextMap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUpScrollArea(QMap<int, VideoDBContext> dbContextMap)
{
    ui->scrollDescription->setStyleSheet("border: 2 px solid rgb(202, 225, 255);");
    QScrollArea* scrollArea = ui->scrollArea;

    QWidget *widg = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widg);
    scrollArea->setWidget(widg);
    scrollArea->setWidgetResizable(true);

    QMap<int, VideoDBContext>::iterator it;

    for (it = dbContextMap.begin(); it != dbContextMap.end(); it ++)
    {
        FilmBlock* filmBlock = new FilmBlock(this, ui, widg, it.value(), it.key(), this->_actions);

        layout->addWidget(filmBlock);
    }

    scrollArea->setWidget(widg);
}

void MainWindow::on_actionAdd_triggered()
{
    AddNewObjectDialog addNewObjectDialog(this, nullptr, this->_actions);

    addNewObjectDialog.setModal(true);
    addNewObjectDialog.exec();
}


void MainWindow::on_actionRemove_triggered()
{
}

void MainWindow::SetDDLItems()
{
    ui->categoriesCombo->addItem("Melodram");
    ui->categoriesCombo->addItem("Drama");
    ui->categoriesCombo->addItem("Action");
    ui->categoriesCombo->addItem("Educational cartoon");
    ui->categoriesCombo->addItem("Anime");
    ui->categoriesCombo->addItem("All");
}

void MainWindow::on_findButton_clicked()
{
    QString category = this->ui->categoriesCombo->currentText();
    QString name = this->ui->nameEdit->text();
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
    }

    if (category == "All")
    {
        this->SetUpScrollArea(dbContextMap);
    }
        else
        {
        if (name.isEmpty())
        {
            this->SetUpScrollArea(FindLogic::FindByCategory(dbContextMap.begin(), dbContextMap.end(), category));
        }
        else
        {
            this->SetUpScrollArea(FindLogic::FindByNameAndCategory(dbContextMap.begin(), dbContextMap.end(), category, name));
        }
    }
}

void MainWindow::on_actionRedo_triggered()
{

}

void MainWindow::on_actionUndo_triggered()
{
    if (!this->_actions.isEmpty())
    {
        int actionId = this->_actions.last().first;
        VideoRepository repos;

        switch (actionId)
        {
            case ActionEnum::ADD:
            {
                repos.Remove(this->_actions.last().second.first);
                break;
            }
            case ActionEnum::REMOVE:
            {
                repos.Add(this->_actions.last().second.second);
                break;
            }
            case ActionEnum::EDIT:
            {
                repos.Update(this->_actions.last().second.second, this->_actions.last().second.first);
                break;
            }
            default:
            {
                break;
            }
        }

        this->_actions.pop_back();
        this->SetUpScrollArea(repos.GetAll());
    }
}
