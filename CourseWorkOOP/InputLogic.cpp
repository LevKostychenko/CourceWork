#include "InputLogic.h"
#include "inputexception.h"

bool InputLogic::IsDateStringValid(QString dateString)
{
    if(dateString.isEmpty())
    {
        return true;
    }

    QRegularExpression matchString("(0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)\\d\\d");
    QRegularExpressionMatch match = matchString.match(dateString);

    if (!match.hasMatch())
    {
        throw InputException("Date should be in format: DD.MM.YYYY.", dateString);
    }

    return true;
}
