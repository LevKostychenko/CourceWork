#include "anime.h"

Anime::Anime()
{

}

Anime::Anime(QString category, QString name, QString description, QString imagePath, QString addingDate,
             QString creatingDate, QString genre, List<QString> voiceActing, int rate) :
    Cartoon(category, name, description, imagePath, addingDate, creatingDate, voiceActing, rate)
{
    this->Genre = genre;
}
