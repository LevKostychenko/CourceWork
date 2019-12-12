#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "VideoRepository.h"
#include "VideoDBContext.h"
#include <QStack>
#include <QMap>
#include <QMainWindow>
#include "ActionEnum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetUpScrollArea(QMap<int, VideoDBContext> dbContextMap);

private:
    Ui::MainWindow *ui;
    void SetDDLItems();
    QStack<QPair<ActionEnum, QPair<int, VideoDBContext>>> _actions;


private slots:
    void on_actionAdd_triggered();

    void on_actionRemove_triggered();

    void on_findButton_clicked();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

};
#endif // MAINWINDOW_H
