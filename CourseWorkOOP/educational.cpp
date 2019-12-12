#include "educational.h"

Educational::Educational()
{

}

Educational::Educational(QString category, QString name, QString description, QString imagePath, QString addingDate,
                         QString creatingDate, QString educationalTheme, List<QString> voiceActing) :
    Cartoon(category, name, description, imagePath, addingDate, creatingDate, voiceActing)
{
    this->EducationalTheme = educationalTheme;
}
