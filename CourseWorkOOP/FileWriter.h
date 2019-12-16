#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <QMap>
#include <QFile>
#include <QString>

class FileWriter
{
public:
    FileWriter();

    void WriteToFile(QFile* file, QString buff);
    void AppendToFile(QFile *file, QString buff);
};

#endif // FILEWRITER_H
