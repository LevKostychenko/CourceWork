#include "video.h"

Video::Video()
{

}

Video::Video(QString category, QString name, QString description, QString imagePath, QString addingDate, QString creatingDate)
{
    this->Category = category;
    this->Name = name;
    this->ImagePath = imagePath;
    this->AddingDate = addingDate;
    this->Description = description;
    this->CreatingDate = creatingDate;
}
