#ifndef MOVIE_H
#define MOVIE_H
#include "video.h"
#include <qstring.h>
#include <qmap.h>

class Movie : public Video
{
public:
    Movie(QString category, QString name, QString description, QString imagePath, QString addingDate,
          QString creatingDate = "", List<QString> cast = List<QString>(), int rate = 0);
    Movie();
    List<QString> Cast;
};

#endif // MOVIE_H
