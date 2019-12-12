#include "EditFilmModelWindow.h"
#include "ui_EditFilmModelWindow.h"
#include "FileException.h"
#include "inputexception.h"
#include <QMessageBox>

EditFilmModelWindow::EditFilmModelWindow(QWidget *parent, VideoDBContext context, int id, MainWindow* mainWindow) :
    QDialog(parent),
    _context(context),
    _mainWindow(mainWindow),
    _id(id),
    ui(new Ui::EditFilmModelWindow)
{
    ui->setupUi(this);
}

EditFilmModelWindow::~EditFilmModelWindow()
{
    delete ui;
}

void EditFilmModelWindow::on_save_clicked()
{
    QString date = ui->dateEdit->text();

    try
    {
        InputLogic::IsDateStringValid(date);
    }
    catch (const InputException& ex)
    {
        ui->dateEdit->setText(ex.ExceptionDescription);
        return;
    }

        QList<QString> qActing = ui->castEdit->text().split(',');
        List<QString> cast;
        for (QList<QString>::iterator it = qActing.begin(); it != qActing.end(); it++)
        {
            cast.PushBack(*it);
        }

        Movie movie(_context.Category, ui->nameEdit->text(), ui->descriptionEdit->toPlainText(), _context.ImagePath,
                                       _context.AddingDate, date, cast);

        VideoRepository repos;

        if (movie.Name.isEmpty())
        {
            movie.Name = _context.Name;
        }

        if (movie.Description.isEmpty())
        {
            movie.Description = _context.Description;
        }

        VideoDBContext context(movie);
        try
        {
            repos.Update(context, _id);
        }
        catch(const FileException& ex)
        {
            QMessageBox::critical(this,"Ошибка","Ошибка номер " + QString::number(ex.ExceptionCode) + " " + ex.ExceptionDescription);
        }
        this->close();
}

void EditFilmModelWindow::on_cancel_clicked()
{
    this->close();
}
