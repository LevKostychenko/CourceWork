#ifndef VIDEOREPOSITORY_H
#define VIDEOREPOSITORY_H
#include "CustomDatabase.h"
#include "VideoDBContext.h"
#include <qfile.h>
#include <qlist.h>
#include "FileReader.h"
#include <QTextStream>
#include "FileWriter.h"

class VideoRepository : public CustomDatabase<VideoDBContext>
{
public:
    void Remove(int id) override;
    void Add(VideoDBContext data) override;
    void Update(VideoDBContext data, int id) override;
    int GetLastId() override;
    QMap<int, VideoDBContext> GetAll() override;

private:
    void WriteToFile(QFile* file, QString data);
    void WriteToFile(QFile* file, List<QString> data);
    QMap<int, VideoDBContext> ReadFromFiles(int count);
    QMap<int, QString> ReadFromFile(QFile* file, int count);
    int GetLastId(QFile* file);
    int GetCountOfEntities(QFile* file);
    void RemoveFromFile(QFile *file, int id);
    void UpdateFile(int id, QString newData, QFile *file);
    void UpdateFile(int id, List<QString> newData, QFile *file);
};

#endif // VIDEOREPOSITORY_H
