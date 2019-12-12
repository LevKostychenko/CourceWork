#ifndef ADDNEWOBJECTDIALOG_H
#define ADDNEWOBJECTDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddNewObjectDialog;
}

class AddNewObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewObjectDialog(MainWindow* mainWindow = nullptr, QWidget *parent = nullptr,
                                QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>& actions = *(new QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>()));
    ~AddNewObjectDialog();

private slots:
    void on_openFileExplorerPushButton_clicked();

    void on_addMoviePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_setDescriptionTextEdit_textChanged();

    void on_setNameTextEdit_textChanged(const QString &arg1);

private:
    Ui::AddNewObjectDialog *ui;
    QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>* _actions;
    MainWindow* _mainWindow;
    void SetDDLItems();
};

#endif // ADDNEWOBJECTDIALOG_H
