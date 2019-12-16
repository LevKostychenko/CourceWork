#include "FileReader.h"
#include <QTextStream>
#include "FileException.h"

FileReader::FileReader()
{

}

QString FileReader::ReadToCount(QFile *file, int count)
{
    QString line;

    if((*file).open(QIODevice::ReadOnly))
    {
        QTextStream stream( &(*file) );

        for(int i = 0; i < count; i++)
        {
            QString eachLine = stream.readLine();
        }

        line = stream.readLine();
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    return line;
}

QString FileReader::ReadAll(QFile *file)
{
    QString buffer;

    if((*file).open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream( &(*file) );

        while (!stream.atEnd())
        {
            buffer.append(stream.readLine() + '\n');
        }

        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    return buffer;
}
