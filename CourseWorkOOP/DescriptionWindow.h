#ifndef DESCRIPTIONWINDOW_H
#define DESCRIPTIONWINDOW_H

#include <QWidget>
#include "VideoDBContext.h"

namespace Ui {
class DescriptionWindow;
}

class DescriptionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DescriptionWindow(QWidget *parent = nullptr, VideoDBContext context = VideoDBContext());
    ~DescriptionWindow();

private:
    Ui::DescriptionWindow *ui;
    VideoDBContext _contex;
};

#endif // DESCRIPTIONWINDOW_H
