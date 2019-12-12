#include "FindLogic.h"

FindLogic::FindLogic()
{

}

QMap<int, VideoDBContext> FindLogic::FindByNameAndCategory(QMap<int, VideoDBContext>::iterator begin,
                                                           QMap<int, VideoDBContext>::iterator end, QString category, QString name)
{
    QMap<int, VideoDBContext> newMap;

    for (QMap<int, VideoDBContext>::iterator cur = begin; cur != end; cur ++)
    {
        if (cur.value().Name == name && cur.value().Category == category)
        {
            newMap.insert(cur.key(), cur.value());
        }
    }

    return newMap;
}

QMap<int, VideoDBContext> FindLogic::FindByCategory(QMap<int, VideoDBContext>::iterator begin, QMap<int, VideoDBContext>::iterator end, QString category)
{
    QMap<int, VideoDBContext> newMap;

    for (QMap<int, VideoDBContext>::iterator cur = begin; cur != end; cur ++)
    {
        if (cur.value().Category == category)
        {
            newMap.insert(cur.key(), cur.value());
        }
    }

    return newMap;
}
