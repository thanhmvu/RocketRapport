#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <string>
#include <QtSql>



class DbManager
{
public:
    DbManager(const QString& path);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
