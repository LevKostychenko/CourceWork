#include "anime.h"

Anime::Anime()
{

}

Anime::Anime(QString category, QString name, QString description, QString imagePath, QString addingDate,
             QString creatingDate, QString genre, List<QString> voiceActing) :
    Cartoon(category, name, description, imagePath, addingDate, creatingDate, voiceActing)
{
    this->Genre = genre;
}
