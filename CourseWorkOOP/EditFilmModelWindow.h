#ifndef EDITFILMMODELWINDOW_H
#define EDITFILMMODELWINDOW_H
#include "VideoDBContext.h"
#include "VideoRepository.h"
#include "mainwindow.h"
#include "InputLogic.h"
#include <QDialog>

namespace Ui {
class EditFilmModelWindow;
}

class EditFilmModelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditFilmModelWindow(QWidget *parent = nullptr, VideoDBContext context = VideoDBContext(), int id = 0, MainWindow* mainWindow = nullptr);
    ~EditFilmModelWindow();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::EditFilmModelWindow *ui;
    VideoDBContext _context;
    int SetRate();
    MainWindow* _mainWindow;
    int _id;
};

#endif // EDITFILMMODELWINDOW_H
