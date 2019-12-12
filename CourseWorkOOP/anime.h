#ifndef ANIME_H
#define ANIME_H
#include "cartoon.h"
#include <qlist.h>
#include <qstring.h>

class Anime : public Cartoon
{
public:
    Anime();
    Anime(QString category, QString name, QString description,
          QString imagePath, QString addingDate, QString creatingDate = "", QString genre = "",
         List<QString> voiceActing = List<QString>());
    QString Genre;
};

#endif // ANIME_H
