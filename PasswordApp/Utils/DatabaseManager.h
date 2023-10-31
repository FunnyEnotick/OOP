#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "Logger.h"


class DatabaseManager
{
public:
    static DatabaseManager* getInstance();
    void connect(QString dbName);
    void createTables();
private:
    DatabaseManager(){};
    QSqlDatabase _database;
    Logger _log;
};

#endif // DATABASEMANAGER_H
