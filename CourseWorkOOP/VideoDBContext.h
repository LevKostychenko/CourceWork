#ifndef VIDEODBCONTEXT_H
#define VIDEODBCONTEXT_H
#include <qstring.h>
//#include <qlist.h>
#include "List.h"
#include "anime.h"
#include "educational.h"
#include "movie.h"

class VideoDBContext
{
public:
    VideoDBContext(QString category, QString name, QString description,
                    QString imagePath, QString addingDate, QString creatingDate = "", QString genre ="", QString educationalTheme = "",
                   List<QString> voiceActing = List<QString>(), List<QString> cast = List<QString>(), int rate = 0);
    VideoDBContext(Movie movie);
    VideoDBContext(Anime anime);
    VideoDBContext();
    VideoDBContext(Educational educationalCartoon);
    VideoDBContext(const VideoDBContext& context);


    List<QString> VoiceActing;
    List<QString> Cast;
    QString Category;
    QString Name;
    QString Description;
    QString ImagePath;
    QString AddingDate;
    QString CreatingDate;
    QString Genre;
    QString EducationalTheme;
    int Rate;

    static QString GetActersString(VideoDBContext context);
};

#endif // VIDEODBCONTEXT_H
