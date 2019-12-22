#include "educational.h"

Educational::Educational()
{

}

Educational::Educational(QString category, QString name, QString description, QString imagePath, QString addingDate,
                         QString creatingDate, QString educationalTheme, List<QString> voiceActing, int rate) :
    Cartoon(category, name, description, imagePath, addingDate, creatingDate, voiceActing, rate)
{
    this->EducationalTheme = educationalTheme;
}
