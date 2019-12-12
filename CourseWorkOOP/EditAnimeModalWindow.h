#ifndef EDITANIMEMODALWINDOW_H
#define EDITANIMEMODALWINDOW_H

#include "VideoDBContext.h"
#include "mainwindow.h"
#include "InputLogic.h"
#include <QDialog>

namespace Ui {
class EditAnimeModalWindow;
}

class EditAnimeModalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditAnimeModalWindow(QWidget *parent = nullptr,  VideoDBContext context = VideoDBContext(), int id = 0, MainWindow* mainWindow = nullptr);
    ~EditAnimeModalWindow();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::EditAnimeModalWindow *ui;
     VideoDBContext _context;
     MainWindow* _mainWindow;
     int _id;
};

#endif // EDITANIMEMODALWINDOW_H
