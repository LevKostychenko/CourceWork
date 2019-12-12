#ifndef INPUTLOGIC_H
#define INPUTLOGIC_H
#include <QRegularExpression>
#include <QString>

class InputLogic
{
public:
    static bool IsDateStringValid(QString dateString);
};

#endif // INPUTLOGIC_H
