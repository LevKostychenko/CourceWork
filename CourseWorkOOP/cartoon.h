#ifndef CARTOON_H
#define CARTOON_H
#include "video.h"
#include <qlist.h>
#include <qstring.h>

class Cartoon : public Video
{
public:
    Cartoon();
    Cartoon(QString category, QString name, QString description,
            QString imagePath, QString addingDate, QString creatingDate = "", List<QString> voiceActing = List<QString>());
    List<QString> VoiceActing;
};

#endif // CARTOON_H
