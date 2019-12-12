#include "EditAnimeModalWindow.h"
#include "ui_EditAnimeModalWindow.h"
#include "VideoRepository.h"
#include "List.h"
#include "FileException.h"
#include "inputexception.h"
#include <QMessageBox>

EditAnimeModalWindow::EditAnimeModalWindow(QWidget *parent,  VideoDBContext context, int id, MainWindow* mainWindow) :
    QDialog(parent),
    _context(context),
    _mainWindow(mainWindow),
    _id(id),
    ui(new Ui::EditAnimeModalWindow)
{
    ui->setupUi(this);
}

EditAnimeModalWindow::~EditAnimeModalWindow()
{
    delete ui;
}

void EditAnimeModalWindow::on_save_clicked()
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

        QList<QString> qActing = ui->voiceActingEdit->text().split(',');
        List<QString> acting;
        for (QList<QString>::iterator it = qActing.begin(); it != qActing.end(); it++)
        {
            acting.PushBack(*it);
        }

        Anime anime("Anime", ui->nameEdit->text(), ui->descriptionEdit->toPlainText(), _context.ImagePath,
                                       _context.AddingDate, date, ui->genreEdit->text(), acting);

         VideoRepository repos;

        if (anime.Name.isEmpty())
        {
            anime.Name = _context.Name;
        }

        if (anime.Description.isEmpty())
        {
            anime.Description = _context.Description;
        }

        VideoDBContext context(anime);
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

void EditAnimeModalWindow::on_cancel_clicked()
{
    this->close();
}
