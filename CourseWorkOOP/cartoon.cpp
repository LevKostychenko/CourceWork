#include "cartoon.h"

Cartoon::Cartoon()
{

}

Cartoon::Cartoon(QString category, QString name, QString description, QString imagePath, QString addingDate, QString creatingDate, List<QString> voiceActing) :
    Video(category, name, description, imagePath, addingDate, creatingDate)
{
    this->VoiceActing = voiceActing;
}
