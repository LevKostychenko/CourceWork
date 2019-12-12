#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include "BaseException.h"

class FileException : public BaseException
{
public:
    FileException(QString description, QString fileName);

    QString FileName;
};

#endif // FILEEXCEPTION_H
