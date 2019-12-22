#include "VideoRepository.h"
#include "FileException.h"
#include "List.h"

void VideoRepository::Add(VideoDBContext context)
{
    QFile VoiceActingTable("VoiceAtingTable.txt");
    QFile CastTable("CastTable.txt");
    QFile CategoryTable("CategoryTable.txt");
    QFile NameTable("NameTable.txt");
    QFile DescriptionTable("DescriptionTable.txt");
    QFile ImagePathTable("ImagePathTable.txt");
    QFile AddingDateTable("AddingDateTable.txt");
    QFile CreatingDateTable("CreatingDateTable.txt");
    QFile GenreTable("GenreTable.txt");
    QFile EducationalThemeTable("EducationalThemeTable.txt");
    QFile RateTable("RateTable.txt");

    WriteToFile(&VoiceActingTable, context.VoiceActing);
    WriteToFile(&CastTable, context.Cast);
    WriteToFile(&CategoryTable, context.Category);
    WriteToFile(&NameTable, context.Name);
    WriteToFile(&ImagePathTable, context.ImagePath);
    WriteToFile(&AddingDateTable, context.AddingDate);
    WriteToFile(&CreatingDateTable, context.CreatingDate);
    WriteToFile(&GenreTable, context.Genre);
    WriteToFile(&EducationalThemeTable, context.EducationalTheme);
    WriteToFile(&DescriptionTable, context.Description);
    WriteToFile(&RateTable, QString::number(context.Rate));
}

void VideoRepository::Update(VideoDBContext data, int id)
{
    QFile VoiceActingTable("VoiceAtingTable.txt");
    QFile CastTable("CastTable.txt");
    QFile CategoryTable("CategoryTable.txt");
    QFile NameTable("NameTable.txt");
    QFile DescriptionTable("DescriptionTable.txt");
    QFile ImagePathTable("ImagePathTable.txt");
    QFile AddingDateTable("AddingDateTable.txt");
    QFile CreatingDateTable("CreatingDateTable.txt");
    QFile GenreTable("GenreTable.txt");
    QFile EducationalThemeTable("EducationalThemeTable.txt");
    QFile RateTable("RateTable.txt");

    UpdateFile(id, data.VoiceActing, &VoiceActingTable);
    UpdateFile(id, data.Cast, &CastTable);
    UpdateFile(id, data.Category, &CategoryTable);
    UpdateFile(id, data.Name, &NameTable);
    UpdateFile(id, data.ImagePath, &ImagePathTable);
    UpdateFile(id, data.AddingDate, &AddingDateTable);
    UpdateFile(id, data.CreatingDate, &CreatingDateTable);
    UpdateFile(id, data.Genre, &GenreTable);
    UpdateFile(id, data.EducationalTheme, &EducationalThemeTable);
    UpdateFile(id, data.Description, &DescriptionTable);
    UpdateFile(id, QString::number(data.Rate), &RateTable);
}

int VideoRepository::GetLastId()
{
    QFile nameTable("NameTable.txt");
    return this->GetLastId(&nameTable);
}

void VideoRepository::Remove(int id)
{
    QFile VoiceActingTable("VoiceAtingTable.txt");
    QFile CastTable("CastTable.txt");
    QFile CategoryTable("CategoryTable.txt");
    QFile NameTable("NameTable.txt");
    QFile DescriptionTable("DescriptionTable.txt");
    QFile ImagePathTable("ImagePathTable.txt");
    QFile AddingDateTable("AddingDateTable.txt");
    QFile CreatingDateTable("CreatingDateTable.txt");
    QFile GenreTable("GenreTable.txt");
    QFile EducationalThemeTable("EducationalThemeTable.txt");
    QFile RateTable("RateTable.txt");

    RemoveFromFile(&VoiceActingTable, id);
    RemoveFromFile(&CastTable, id);
    RemoveFromFile(&CategoryTable, id);
    RemoveFromFile(&NameTable, id);
    RemoveFromFile(&ImagePathTable, id);
    RemoveFromFile(&AddingDateTable, id);
    RemoveFromFile(&CreatingDateTable, id);
    RemoveFromFile(&GenreTable, id);
    RemoveFromFile(&EducationalThemeTable, id);
    RemoveFromFile(&DescriptionTable, id);
    RemoveFromFile(&RateTable, id);
}

QMap<int, VideoDBContext> VideoRepository::GetAll()
{
  QMap<int, VideoDBContext> map;
  QPair<int, VideoDBContext> keyValuePair;
  QFile NameTable("NameTable.txt");

  int entitiesCount = GetCountOfEntities(&NameTable);
  if (entitiesCount == -1)
  {
    return map;
  }
  for (int i = 0; i < entitiesCount; i++)
  {
    keyValuePair = ReadFromFiles(i);
    map.insert(keyValuePair.first, keyValuePair.second);
  }

  return map;
}

void VideoRepository::WriteToFile(QFile* file, QString data)
{
    QString id = QString::number(GetLastId(file) + 1);
    QString buff;
    FileWriter fwriter;

    if (id == "0")
    {
        return;
    }
    buff.append(id + " " + data + "\n");

    fwriter.AppendToFile(file, buff);
}

void VideoRepository::WriteToFile(QFile *file, List<QString> data)
{
    QString id = QString::number(GetLastId(file) + 1);
    QString buff;
    FileWriter fwriter;

    if (id == "0")
    {
        return;
    }
    Iterator<QString> it = data.begin();
    buff.append(id + " ");
    for (it; it != data.end(); it++)
    {
        buff.append(*it +',');
    }

    buff.append("\n");
    fwriter.AppendToFile(file, buff);
}

int VideoRepository::GetLastId(QFile* file)
{
    QString id = "0";
    FileReader freader;
    QString buff = freader.ReadAll(file);
    QStringList strlist = buff.split('\n');
    QStringList fields;
    for (QStringList::iterator iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        QString line = *iter;
        if (!line.isEmpty() && line != "\n")
        {
            fields.append(line);
        }
    }
    if (!fields.empty())
    {
        id = fields.last().split(' ')[0];
    }

    return id.toInt();
}

int VideoRepository::GetCountOfEntities(QFile *file)
{
    int count = 0;
    FileReader freader;
    QString buff = freader.ReadAll(file);
    QStringList strlist = buff.split('\n');
    for (QStringList::iterator iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        QString line = *iter;
        if (!line.isEmpty() && line != "\n")
        {
            count++;
        }
    }

    return count;
}

QPair<int, VideoDBContext> VideoRepository::ReadFromFiles(int count)
{
    QFile VoiceAtingTable("VoiceAtingTable.txt");
    QFile CastTable("CastTable.txt");
    QFile CategoryTable("CategoryTable.txt");
    QFile NameTable("NameTable.txt");
    QFile DescriptionTable("DescriptionTable.txt");
    QFile ImagePathTable("ImagePathTable.txt");
    QFile AddingDateTable("AddingDateTable.txt");
    QFile CreatingDateTable("CreatingDateTable.txt");
    QFile GenreTable("GenreTable.txt");
    QFile EducationalThemeTable("EducationalThemeTable.txt");
    QFile RateTable("RateTable.txt");

    QString name;
    QString imagePath;
    QString addingDate;
    QString creatingDate;
    QString genre;
    QString educationalTheme;
    QString category;
    QString description;
    int rate;

    List<QString> cast;
    List<QString> voiceActing;

    int id;

    QPair<int, QString> namePair = ReadFromFile(&NameTable, count);
    if (!(namePair.first == 0))
    {
        name = namePair.second;
        imagePath = ReadFromFile(&ImagePathTable, count).second;
        addingDate = ReadFromFile(&AddingDateTable, count).second;
        creatingDate = ReadFromFile(&CreatingDateTable, count).second;
        genre = ReadFromFile(&GenreTable, count).second;
        educationalTheme = ReadFromFile(&EducationalThemeTable, count).second;
        category = ReadFromFile(&CategoryTable, count).second;
        description = ReadFromFile(&DescriptionTable, count).second;
        rate = ReadFromFile(&RateTable, count).second.toInt();

        QList<QString> qcast = ReadFromFile(&CastTable, count).second.split(',');
        QList<QString> qVoiceActing = ReadFromFile(&VoiceAtingTable, count).second.split(',');

        for (QList<QString>::iterator it = qcast.begin(); it != qcast.end(); it++)
        {
            cast.PushBack(*it);
        }

        for (QList<QString>::iterator it = qVoiceActing.begin(); it != qVoiceActing.end(); it++)
        {
            voiceActing.PushBack(*it);
        }

        id = namePair.first;
    }

    QPair<int, VideoDBContext> keyValue = qMakePair(id, VideoDBContext(category, name, description, imagePath, addingDate, creatingDate, genre, educationalTheme, voiceActing, cast, rate));
    return keyValue;
}

QPair<int, QString> VideoRepository::ReadFromFile(QFile* file, int count)
{
    int id = 0;
    QString data = "";
    QPair<int, QString> pair;
    FileReader freader;
    QString line = freader.ReadToCount(file, count);
    data = line.section(' ', 1);
    id = line.split(' ')[0].toInt();
    pair = qMakePair(id, data);
    return pair;
}

void VideoRepository::RemoveFromFile(QFile *file, int id)
{
    QString buffer;
    FileReader freader;
    FileWriter fwriter;
    QString currentData = freader.ReadAll(file);
    QStringList strlist = currentData.split('\n');
    for (QStringList::iterator iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        QString line = *iter;
        if (!line.isEmpty() && line != "\n")
        {
            int _id = line.split(' ')[0].toInt();

            if (_id != id)
            {
                buffer.append(line + "\n");
            }
        }
    }

    fwriter.WriteToFile(file, buffer);
}

void VideoRepository::UpdateFile(int id, QString newData, QFile *file)
{
    QString buffer;
    FileReader freader;
    FileWriter fwriter;
    QString currentData = freader.ReadAll(file);
    QStringList strlist = currentData.split('\n');
    for (QStringList::iterator iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        QString line = *iter;
        if (!line.isEmpty() && line != "\n")
        {
            int _id = line.split(' ')[0].toInt();

            if (_id != id)
            {
                buffer.append(line + "\n");
            }
            else
            {
                QString newLine = QString::number(_id) + " " + newData;
                buffer.append(newLine + "\n");
            }
        }
    }

    fwriter.WriteToFile(file, buffer);
}

void VideoRepository::UpdateFile(int id, List<QString> newData, QFile *file)
{
    QString buffer;
    FileReader freader;
    FileWriter fwriter;
    QString currentData = freader.ReadAll(file);
    QStringList strlist = currentData.split('\n');
    for (QStringList::iterator iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        QString line = *iter;
        if (!line.isEmpty() && line != "\n")
        {
            int _id = line.split(' ')[0].toInt();

            if (_id != id)
            {
                buffer.append(line + "\n");
            }
            else
            {
                QString newStringData;
                for (Iterator<QString> it = newData.begin(); it != newData.end(); it++)
                {
                    newStringData += *it;
                }

                QString newLine = QString::number(_id) + " " + newStringData;
                buffer.append(newLine + "\n");
            }
        }
    }

    fwriter.WriteToFile(file, buffer);
}


