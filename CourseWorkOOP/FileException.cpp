#include "FileException.h"
#include "ExceptionCodeEnum.h"

FileException::FileException(QString description, QString fileName) :
    BaseException(description, ExceptionCodeEnum::FILEHASNOTOPENED),
    FileName(fileName)
{

}
