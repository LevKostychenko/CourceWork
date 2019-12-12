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

        Educational educationalCartoon("Educational", ui->nameEdit->text(), ui->descriptionEdit->toPlainText(), _context.ImagePath,
                                       _context.AddingDate, date, ui->educationalThemeEdit->text(), acting);

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
