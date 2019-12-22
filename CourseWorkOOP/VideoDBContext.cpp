#include "VideoDBContext.h"

VideoDBContext::VideoDBContext(QString category, QString name, QString description,
                QString imagePath, QString addingDate, QString creatingDate, QString genre, QString educationalTheme,
                List<QString> voiceActing, List<QString> cast, int rate)
{
    this->Cast = cast;
    this->VoiceActing = voiceActing;
    this->Name = name;
    this->Genre = genre;
    this->Category = category;
    this->ImagePath = imagePath;
    this->AddingDate = addingDate;
    this->Description = description;
    this->CreatingDate = creatingDate;
    this->EducationalTheme = educationalTheme;
    this->Rate = rate;
}

VideoDBContext::VideoDBContext(Movie movie)
{
    this->Cast = movie.Cast;
    this->Name = movie.Name;
    this->Genre = "";
    this->Category = movie.Category;
    this->ImagePath = movie.ImagePath;
    this->AddingDate = movie.AddingDate;
    this->Description = movie.Description;
    this->VoiceActing = List<QString>();
    this->CreatingDate = movie.CreatingDate;
    this->EducationalTheme = "";
    this->Rate = movie.Rate;
}

VideoDBContext::VideoDBContext(Anime anime)
{
    this->Cast = List<QString>();
    this->Name = anime.Name;
    this->Genre = anime.Genre;
    this->Category = anime.Category;
    this->ImagePath = anime.ImagePath;
    this->AddingDate = anime.AddingDate;
    this->Description = anime.Description;
    this->VoiceActing = anime.VoiceActing;
    this->CreatingDate = anime.CreatingDate;
    this->EducationalTheme = "";
    this->Rate = anime.Rate;
}

VideoDBContext::VideoDBContext()
{

}

VideoDBContext::VideoDBContext(Educational educationalCartoon)
{
    this->Cast = List<QString>();
    this->Name = educationalCartoon.Name;
    this->Genre = "";
    this->Category = educationalCartoon.Category;
    this->ImagePath = educationalCartoon.ImagePath;
    this->AddingDate = educationalCartoon.AddingDate;
    this->Description = educationalCartoon.Description;
    this->VoiceActing = educationalCartoon.VoiceActing;
    this->CreatingDate = educationalCartoon.CreatingDate;
    this->EducationalTheme = educationalCartoon.EducationalTheme;
    this->Rate = educationalCartoon.Rate;
}

VideoDBContext::VideoDBContext(const VideoDBContext &context)
{
    this->Name = context.Name;
    this->Cast = context.Cast;
    this->Genre = context.Genre;
    this->Category = context.Category;
    this->ImagePath = context.ImagePath;
    this->AddingDate = context.AddingDate;
    this->Description = context.Description;
    this->VoiceActing = context.VoiceActing;
    this->CreatingDate = context.CreatingDate;
    this->EducationalTheme = context.EducationalTheme;
    this->Rate = context.Rate;
}

QString VideoDBContext::GetActersString(VideoDBContext context)
{
    QString cast = "";

    if (context.Category == "Anime" || context.Category == "Educational cartoon")
    {
        for (Iterator<QString> it = context.VoiceActing.begin(); it != context.VoiceActing.end(); it++)
        {
            if (!((*it).isEmpty()))
            {
                cast += *it + ", ";
            }
        }

        if (!cast.isEmpty())
        {
            cast = "Voice acting: " + cast;
        }
    }
    else
    {
        for (Iterator<QString> it = context.Cast.begin(); it != context.Cast.end(); it++)
        {
            if (!((*it).isEmpty()))
            {
                cast += *it + ", ";
            }

            if (!cast.isEmpty())
            {
                cast = "Cast: " + cast;
            }
        }
    }

    return cast;
}
