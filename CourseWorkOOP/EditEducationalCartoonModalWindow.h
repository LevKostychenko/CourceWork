#ifndef EDITEDUCATIONALCARTOONMODALWINDOW_H
#define EDITEDUCATIONALCARTOONMODALWINDOW_H

#include "VideoDBContext.h"
#include "VideoRepository.h"
#include "mainwindow.h"
#include "InputLogic.h"
#include <QDialog>

namespace Ui {
class EditEducationalCartoonModalWindow;
}

class EditEducationalCartoonModalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditEducationalCartoonModalWindow(QWidget *parent = nullptr, VideoDBContext context = VideoDBContext(), int id = 0, MainWindow* mainWindow = nullptr);
    ~EditEducationalCartoonModalWindow();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::EditEducationalCartoonModalWindow *ui;
    VideoDBContext _context;
    MainWindow* _mainWindow;
    int _id;
};

#endif // EDITEDUCATIONALCARTOONMODALWINDOW_H
