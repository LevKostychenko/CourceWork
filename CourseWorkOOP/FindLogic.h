#ifndef FINDLOGIC_H
#define FINDLOGIC_H
#include "VideoDBContext.h"
#include "VideoRepository.h"
#include <QMap>
#include <QString>

class FindLogic
{
public:
    FindLogic();

    QMap<int, VideoDBContext>::iterator it;

    static QMap<int, VideoDBContext> FindByNameAndCategory(QMap<int, VideoDBContext>::iterator begin,
                                                           QMap<int, VideoDBContext>::iterator end, QString category, QString name);
    static QMap<int, VideoDBContext> FindByCategory(QMap<int, VideoDBContext>::iterator begin,
                                                    QMap<int, VideoDBContext>::iterator end, QString category);
};

#endif // FINDLOGIC_H
