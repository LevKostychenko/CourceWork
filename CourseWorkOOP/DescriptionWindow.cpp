#include "DescriptionWindow.h"
#include "ui_DescriptionWindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

DescriptionWindow::DescriptionWindow(QWidget *parent, VideoDBContext context) :
    QWidget(parent),
    ui(new Ui::DescriptionWindow),
    _contex(context)
{
    ui->setupUi(this);
    QFont nameFont( "Arial", 20, QFont::Bold);
    QFont creatingDateFont( "Arial", 15);
    QVBoxLayout* verticalLayout = new QVBoxLayout();
    QHBoxLayout* horisontalContainer = new QHBoxLayout();
    QVBoxLayout* verticalNameCategoryLayout = new QVBoxLayout();

    QLabel* imageContainer = new QLabel();
    QLabel* nameText = new QLabel();
    QLabel* categoryText = new QLabel();
    QLabel* descriptionText = new QLabel();
    QLabel* castText = new QLabel();
    QLabel* genreText = new QLabel();
    QLabel* creatingDateText = new QLabel();

    QImage image(context.ImagePath);
    int w = image.width();
    int h = image.height();

    if (w >= 220 || h >= 220)
    {
        int diff = w - 220;

        w -= diff;
        h -= diff;
    }

    imageContainer->setPixmap(QPixmap::fromImage(image).scaled(w, h, Qt::KeepAspectRatio));
    nameText->setText(context.Name);
    nameText->setFont(nameFont);
    creatingDateText->setText(context.CreatingDate);
    creatingDateText->setFont(creatingDateFont);
    categoryText->setText(context.Category);
    descriptionText->setText(context.Description);
    QString cast = VideoDBContext::GetActersString(context);

    verticalNameCategoryLayout->addWidget(nameText);
    verticalNameCategoryLayout->addWidget(creatingDateText);
    verticalNameCategoryLayout->addWidget(categoryText);
    if (context.Category == "Anime")
    {
        if (!context.Genre.isEmpty())
        {
            genreText->setText("Genre: " + context.Genre);
        }
    }
    if (context.Category == "Educational cartoon")
    {
        if (!context.EducationalTheme.isEmpty())
        {
            genreText->setText("Educational theme: " + context.EducationalTheme);
        }
    }

    if (!cast.isEmpty())
    {
        castText->setText(cast);
        verticalNameCategoryLayout->addWidget(castText);
    }

    horisontalContainer->addWidget(imageContainer);
    horisontalContainer->addLayout(verticalNameCategoryLayout);

    verticalLayout->addLayout(horisontalContainer);
    verticalLayout->addWidget(descriptionText);

    this->setLayout(verticalLayout);
}

DescriptionWindow::~DescriptionWindow()
{
    delete ui;
}
