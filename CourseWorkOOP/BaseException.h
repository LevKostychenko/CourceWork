#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H
#include <QString>
#include "ExceptionCodeEnum.h"
class BaseException
{
public:
    BaseException(QString description, int code);
    int ExceptionCode;
    QString ExceptionDescription;
};

#endif // BASEEXCEPTION_H
