#include "movie.h"

Movie::Movie()
{

}

Movie::Movie(QString category, QString name, QString description, QString imagePath, QString addingDate,
             QString creatingDate, List<QString> cast) :
    Video(category, name, description, imagePath, addingDate, creatingDate)
{
    this->Cast = cast;
}
