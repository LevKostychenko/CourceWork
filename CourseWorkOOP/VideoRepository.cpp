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
    QFile EducationalThemeTable("EducationalThemeTable");

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
    QFile EducationalThemeTable("EducationalThemeTable");

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
}

int VideoRepository::GetLastId()
{
    QFile nameTable("NameTable.txt");
    int _id;

    if(nameTable.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&nameTable);
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            _id = line.split(' ')[0].toInt();
        }

        nameTable.close();
    }
    else
    {
        throw FileException("Cannot open file", nameTable.fileName());
    }

    return _id;
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
    QFile EducationalThemeTable("EducationalThemeTable");

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
}

QMap<int, VideoDBContext> VideoRepository::GetAll()
{
  QMap<int, VideoDBContext> map;
  QMap<int, VideoDBContext> keyValuePair;
  QFile NameTable("NameTable.txt");

  int entitiesCount = GetCountOfEntities(&NameTable);
  if (entitiesCount == -1)
  {
    return map;
  }
  for (int i = 0; i < entitiesCount; i++)
  {
    keyValuePair = ReadFromFiles(i);
    map.insert(keyValuePair.firstKey(), keyValuePair.value(keyValuePair.firstKey()));
  }

  return map;
}

void VideoRepository::WriteToFile(QFile* file, QString data)
{
    QString id = QString::number(GetLastId(file) + 1);

    if ( (*file).open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        QTextStream stream( &(*file) );
        stream << id << " " << data << endl;
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    (*file).close();
}

void VideoRepository::WriteToFile(QFile *file, List<QString> data)
{
    QString id = QString::number(GetLastId(file) + 1);

    if (id == "0")
    {
        return;
    }
    auto it = data.begin();

    if ( (*file).open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        QTextStream stream( &(*file) );
        stream << id << " ";
        for (it; it != data.end(); it++)
        {
            stream << *it << ',';
        }

        stream << endl;
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    (*file).close();
}

int VideoRepository::GetLastId(QFile* file)
{
    QString id = "0";

    if ((*file).open(QIODevice::ReadWrite))
    {
        QTextStream stream( &(*file) );
        QStringList fields;
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            fields.append(line);
        }

        if (!fields.empty())
        {
            id = fields.last().split(' ')[0];
        }
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }


    (*file).close();

    return id.toInt();
}

int VideoRepository::GetCountOfEntities(QFile *file)
{
    int count = 0;

    if((*file).open(QIODevice::ReadOnly))
    {
        QTextStream stream( &(*file) );
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            count++;
        }

        file->close();
        return count;
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    return 0;
}

QMap<int, VideoDBContext> VideoRepository::ReadFromFiles(int count)
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
    QFile EducationalThemeTable("EducationalThemeTable");

    QString name;
    QString imagePath;
    QString addingDate;
    QString creatingDate;
    QString genre;
    QString educationalTheme;
    QString category;
    QString description;

    List<QString> cast;
    List<QString> voiceActing;

    int id;

    QMap<int, QString> nameMap = ReadFromFile(&NameTable, count);
    if (!(nameMap.firstKey() == 0))
    {
        name = nameMap.first();
        imagePath = ReadFromFile(&ImagePathTable, count).first();
        addingDate = ReadFromFile(&AddingDateTable, count).first();
        creatingDate = ReadFromFile(&CreatingDateTable, count).first();
        genre = ReadFromFile(&GenreTable, count).first();
        educationalTheme = ReadFromFile(&EducationalThemeTable, count).first();
        category = ReadFromFile(&CategoryTable, count).first();
        description = ReadFromFile(&DescriptionTable, count).first();

        QList<QString> qcast = ReadFromFile(&CastTable, count).first().split(',');
        QList<QString> qVoiceActing = ReadFromFile(&VoiceAtingTable, count).first().split(',');

        for (QList<QString>::iterator it = qcast.begin(); it != qcast.end(); it++)
        {
            cast.PushBack(*it);
        }

        for (QList<QString>::iterator it = qVoiceActing.begin(); it != qVoiceActing.end(); it++)
        {
            voiceActing.PushBack(*it);
        }

        id = nameMap.firstKey();
    }

    QMap<int, VideoDBContext> map;
    map.insert(id, VideoDBContext(category, name, description, imagePath, addingDate, creatingDate, genre, educationalTheme, voiceActing, cast));
    return map;
}

QMap<int, QString> VideoRepository::ReadFromFile(QFile* file, int count)
{
    int id = 0;
    QString data = "";
    QMap<int, QString> map;

    if((*file).open(QIODevice::ReadOnly))
    {
        QTextStream stream( &(*file) );

        for(int i = 0; i < count; i++)
        {
            QString line = stream.readLine();
        }

        QString line = stream.readLine();
        data = line.section(' ', 1);
        id = line.split(' ')[0].toInt();

        file->close();
        map.insert(id, data);
        return map;
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

    map.insert(id, data);
    return map;
}

void VideoRepository::RemoveFromFile(QFile *file, int id)
{
    QString buffer;

    if((*file).open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream( &(*file) );

        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            int _id = line.split(' ')[0].toInt();
            if (_id != id)
            {
                buffer.append(line + "\n");
            }
        }

        file->resize(0);
        stream << buffer;
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

}

void VideoRepository::UpdateFile(int id, QString newData, QFile *file)
{
    QString buffer;

    if((*file).open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream( &(*file) );

        while (!stream.atEnd())
        {
            QString line = stream.readLine();
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

        file->resize(0);
        stream << buffer;
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }

}

void VideoRepository::UpdateFile(int id, List<QString> newData, QFile *file)
{
    QString buffer;

    if((*file).open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream( &(*file) );

        while (!stream.atEnd())
        {
            QString line = stream.readLine();
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

        file->resize(0);
        stream << buffer;
        file->close();
    }
    else
    {
        throw FileException("Cannot open file", file->fileName());
    }
}


