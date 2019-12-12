#include "BaseException.h"

BaseException::BaseException(QString description, int code) :
    ExceptionDescription(description),
    ExceptionCode(code)
{

}
