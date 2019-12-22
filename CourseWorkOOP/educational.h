#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H
#include "cartoon.h"
#include <qlist.h>
#include <qstring.h>

class Educational : public Cartoon
{
public:
    Educational();
    Educational(QString category, QString name, QString description,
                QString imagePath, QString addingDate, QString creatingDate = "", QString educationalTheme = "",
               List<QString> voiceActing = List<QString>(), int rate = 0);

    QString EducationalTheme;
};

#endif // EDUCATIONAL_H
