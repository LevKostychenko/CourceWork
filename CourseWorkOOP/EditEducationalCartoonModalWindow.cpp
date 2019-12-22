#include "EditEducationalCartoonModalWindow.h"
#include "ui_EditEducationalCartoonModalWindow.h"
#include "educational.h"
#include "FileException.h"
#include "inputexception.h"
#include <QMessageBox>

EditEducationalCartoonModalWindow::EditEducationalCartoonModalWindow(QWidget *parent, VideoDBContext context, int id, MainWindow* mainWindow) :
    QDialog(parent),
    _context(context),
    _mainWindow(mainWindow),
    _id(id),
    ui(new Ui::EditEducationalCartoonModalWindow)
{
    ui->setupUi(this);
}

EditEducationalCartoonModalWindow::~EditEducationalCartoonModalWindow()
{
    delete ui;
}

void EditEducationalCartoonModalWindow::on_save_clicked()
{
    QString date = ui->dateEdit->text();
    int rate;

    try
    {
        InputLogic::IsDateStringValid(date);
    }
    catch (const InputException& ex)
    {
        ui->dateEdit->setText(ex.ExceptionDescription);
        return;
    }

    if (date.isEmpty())
    {
        date = _context.CreatingDate;
    }

    if (SetRate() == 0)
    {
        rate = _context.Rate;
    }

        QList<QString> qActing = ui->voiceActingEdit->text().split(',');
        List<QString> acting;
        for (QList<QString>::iterator it = qActing.begin(); it != qActing.end(); it++)
        {
            acting.PushBack(*it);
        }

        Educational educationalCartoon("Educational", ui->nameEdit->text(), ui->descriptionEdit->toPlainText(), _context.ImagePath,
                                       _context.AddingDate, date, ui->educationalThemeEdit->text(), acting, rate);

        VideoRepository repos;

        if (educationalCartoon.Name.isEmpty())
        {
            educationalCartoon.Name = _context.Name;
        }

        if (educationalCartoon.Description.isEmpty())
        {
            educationalCartoon.Description = _context.Description;
        }

        VideoDBContext context(educationalCartoon);
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

void EditEducationalCartoonModalWindow::on_cancel_clicked()
{
    this->close();
}

int EditEducationalCartoonModalWindow::SetRate()
{
    int _rate = 0;

    if (ui->rate1->isChecked())
    {
        _rate = 1;
    }
    else if (ui->rate2->isChecked())
    {
        _rate = 2;
    }
    else if (ui->rate3->isChecked())
    {
        _rate = 3;
    }
    else if (ui->rate4->isChecked())
    {
        _rate = 4;
    }
    else if (ui->rate5->isChecked())
    {
        _rate = 5;
    }

    return _rate;
}
