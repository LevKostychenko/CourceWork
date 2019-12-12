#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H
#include <QString>
#include "BaseException.h"

class InputException : public BaseException
{
public:
    InputException(QString description, QString wrongVariant);

    QString WrongVariant;
};

#endif // INPUTEXCEPTION_H
