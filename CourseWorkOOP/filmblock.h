#ifndef FILMBLOCK_H
#define FILMBLOCK_H

#include <QWidget>
#include "VideoDBContext.h"
#include "VideoRepository.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class FilmBlock;
}

class FilmBlock : public QWidget
{
    Q_OBJECT

public:
    explicit FilmBlock(MainWindow* mainWindow = nullptr, Ui::MainWindow* uiMainWindow = nullptr, QWidget *parent = nullptr, VideoDBContext context = VideoDBContext(), int id = 0,
                       QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>& actions = *(new QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>()));
    ~FilmBlock();

public slots:
    void slotDelete();
    void slotEdit();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::FilmBlock *ui;
    MainWindow* _mainWindow;
    Ui::MainWindow* _uiMainWindow;
    QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>>* _actions;
    VideoDBContext _context;
    int _id;
    void ShowPopUpMenu(QPoint pos);
};

#endif // FILMBLOCK_H
