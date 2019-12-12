#include "InputException.h"

InputException::InputException(QString description, QString wrongVariant) :
    BaseException(description, ExceptionCodeEnum::INPUTISNOTCORRECT),
    WrongVariant(wrongVariant)
{

}
