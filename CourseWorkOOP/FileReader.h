#ifndef FILEREADER_H
#define FILEREADER_H
#include <QMap>
#include <QFile>
#include <QString>

class FileReader
{
public:
    FileReader();

    QString ReadToCount(QFile* file, int count);
    QString ReadAll(QFile* file);
};

#endif // FILEREADER_H
