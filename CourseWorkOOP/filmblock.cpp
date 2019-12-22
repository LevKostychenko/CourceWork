#include "filmblock.h"
#include "ui_filmblock.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QScrollArea>
#include "DescriptionWindow.h"
#include "EditAnimeModalWindow.h"
#include "EditEducationalCartoonModalWindow.h"
#include "EditFilmModelWindow.h"
#include "FileException.h"
#include <QDialog>

FilmBlock::FilmBlock(MainWindow* mainWindow, Ui::MainWindow* uiMainWindow, QWidget *parent, VideoDBContext context, int id, QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>& actions) :
    QWidget(parent),
    ui(new Ui::FilmBlock),
    _mainWindow(mainWindow),
    _actions(&actions),
    _uiMainWindow(uiMainWindow),
    _context(context),
    _id(id)
{
    ui->setupUi(this);
    QFont nameFont( "Arial", 15, QFont::Bold);
    QFont categoryFont( "Arial", 10, QFont::Bold);
    QFont rateFont =QFont("Arial", 12, QFont::Bold);

    QLabel* rateText = new QLabel();

    if (context.Rate > 0 && context.Rate < 3)
    {
        rateText->setStyleSheet("color: red;");
    }
    else if (context.Rate > 2 && context.Rate < 5)
    {
        rateText->setStyleSheet("color: #FEA43E;");
    }
    else if (context.Rate == 5)
    {
        rateText->setStyleSheet("color: #2FDE35;");
    }
    else
    {
        rateText->setStyleSheet("color: #B4BAB4;");
    }

    QHBoxLayout* horisontalBoxLayot = new QHBoxLayout();
    QLabel* imageContainer = new QLabel();

    QImage image(context.ImagePath);
    int w = image.width();
    int h = image.height();

    if (w >= 90 || h >= 90)
    {
        int diff = w - 90;

        w -= diff;
        h -= diff;
    }

    QVBoxLayout *verticalBoxLayot = new QVBoxLayout();
    QLabel* nameText = new QLabel();
    QLabel* categoryText = new QLabel();
    imageContainer->setPixmap(QPixmap::fromImage(image).scaled(w, h, Qt::KeepAspectRatio));
    nameText->setText(context.Name);
    nameText->setFont(nameFont);
    rateText->setText("Rate: " + QString::number(context.Rate));
    rateText->setFont(rateFont);
    categoryText->setText(context.Category);
    categoryText->setFont(categoryFont);
    verticalBoxLayot->addWidget(nameText);
    verticalBoxLayot->addWidget(rateText);
    verticalBoxLayot->addWidget(categoryText);
    horisontalBoxLayot->addWidget(imageContainer);
    horisontalBoxLayot->addLayout(verticalBoxLayot);    
    this->setLayout(horisontalBoxLayot);
}

FilmBlock::~FilmBlock()
{
    delete ui;
}

void FilmBlock::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    QPoint locPos = event->pos();
    locPos.setX(x+(x*2));
    if (event->button() == Qt::RightButton)
    {
        ShowPopUpMenu(locPos);
    }
    else
    {
        DescriptionWindow* descriptionWindow = new DescriptionWindow(nullptr, this->_context);

        QScrollArea* scroll = this->_uiMainWindow->scrollDescription;

        scroll->setWidget(descriptionWindow);
    }
}

void FilmBlock::ShowPopUpMenu(QPoint pos)
{
    int currId = this->_id;
    QMenu *menu=new QMenu();
    pos.setY(pos.y()+300);
    menu->addAction(QString("Edit"), this,SLOT(slotEdit()));
    menu->addAction(QString("Delete"), this,SLOT(slotDelete()));
    menu->popup(pos, nullptr);
}

void FilmBlock::slotDelete()
{
    this->_actions->append(qMakePair(ActionEnum::REMOVE, qMakePair(this->_id, this->_context)));
    VideoRepository repos;
    try
    {
        repos.Remove(this->_id);
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
         this->_actions->pop_back();
        return;
    }

    _mainWindow->SetUpScrollArea(repos.GetAll());
}

void FilmBlock::slotEdit()
{
    this->_actions->append(qMakePair(ActionEnum::EDIT, qMakePair(this->_id, this->_context)));

    if (this->_context.Category == "Anime")
    {
        EditAnimeModalWindow animeModal(this, this->_context, this->_id, this->_mainWindow);

        animeModal.setModal(true);
        animeModal.exec();
    }
    else if (this->_context.Category == "Educational cartoon")
    {
        EditEducationalCartoonModalWindow cartoonModal(this, this->_context, this->_id, this->_mainWindow);

        cartoonModal.setModal(true);
        cartoonModal.exec();
    }
    else if (this->_context.Category == "Action"
             || this->_context.Category == "Melodram"
             || this->_context.Category == "Melodram")
    {
        EditFilmModelWindow movieModal(this, this->_context, this->_id, this->_mainWindow);

        movieModal.setModal(true);
        movieModal.exec();
    }

    VideoRepository repos;
    try
    {
        _mainWindow->SetUpScrollArea(repos.GetAll());
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
        this->_actions->pop_back();
    }
}
