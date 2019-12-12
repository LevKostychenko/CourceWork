#ifndef VIDEO_H
#define VIDEO_H
#include <qstring.h>
#include "List.h"

class Video
{
public:
    Video();
    Video(QString category, QString name, QString description, QString imagePath, QString addingDate, QString creatingDate = "");
   // virtual ~Video();

    QString Category;
    QString Name;
    QString Description;
    QString ImagePath;
    QString AddingDate;
    QString CreatingDate;
};

#endif // VIDEO_H
