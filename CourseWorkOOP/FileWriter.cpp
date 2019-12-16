#include "FileWriter.h"
#include <QTextStream>
#include "FileException.h"

FileWriter::FileWriter()
{

}

void FileWriter::WriteToFile(QFile *file, QString buff)
{
    QString buffer;

    if((*file).open(QIODevice::ReadWrite | QIODevice::Text))
    {
        file->resize(0);
        QTextStream stream( &(*file) );

        stream << buff;
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }
}

void FileWriter::AppendToFile(QFile *file, QString buff)
{
    QString buffer;

    if((*file).open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream( &(*file) );

        stream << buff;
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }
}

