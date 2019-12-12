#ifndef CUSTOMDATABASE_H
#define CUSTOMDATABASE_H
#include <QMap>

template<typename T>
class CustomDatabase
{
public:
    virtual void Add(T data) = 0;
    virtual void Remove(int id) = 0;
    virtual void Update(T data, int id) = 0;
    virtual int GetLastId() = 0;
    virtual QMap<int, T> GetAll() = 0;
};

#endif // CUSTOMDATABASE_H
