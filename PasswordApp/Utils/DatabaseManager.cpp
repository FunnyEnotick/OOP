#include "DatabaseManager.h"



DatabaseManager *DatabaseManager::getInstance()
{
    static DatabaseManager instance;
    return &instance;
}

void DatabaseManager::connect(QString dbName)
{
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName(dbName);
    if (_database.open()) {
        _log.info("Успешное соединение с базой данных.");
    } else {
        _log.error("Ошибка соединения с базой данных." + _database.lastError().text());
        exit(EXIT_FAILURE);
    }
}

void DatabaseManager::createTables()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS users("
                  "id INTEGER PRIMARY KEY, "
                  "login TEXT UNIQUE, "
                  "password TEXT, "
                  "is_admin BOOLEAN DEFAULT 0)");
    if (! query.exec()) {
        _log.warning("Ошибка создания таблица users. " + query.lastError().text());
    }

    query.prepare("CREATE TABLE IF NOT EXISTS client("
                  "id INTEGER PRIMARY KEY, "
                  "name TEXT , "
                  "surname TEXT, "
                  "patronymic TEXT, "
                  "phone TEXT UNIQUE, "
                  "email TEXT UNIQUE )");
    if (! query.exec()) {
        _log.warning("Ошибка создания таблица client. " + query.lastError().text());
    }

    query.prepare("CREATE TABLE IF NOT EXISTS book("
                  "id INTEGER PRIMARY KEY, "
                  "name TEXT , "
                  "surname TEXT, "
                  "patronymic TEXT, "
                  "country TEXT, "
                  "city TEXT, "
                  "hotel TEXT, "
                  "people TEXT, "
                  "sum TEXT UNIQUE )");
    if (! query.exec()) {
        _log.warning("Ошибка создания таблица book. " + query.lastError().text());
    }

    query.prepare("CREATE TABLE IF NOT EXISTS city_cost("
                  "id INTEGER PRIMARY KEY, "
                  "city TEXT  , "
                  "cost INTEGER)");
    if (! query.exec()) {
            _log.warning("Ошибка создания таблица city_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO city_cost (id,city,cost) VALUES (:id,:city,:cost)");
        query.bindValue(":id", 0);
        query.bindValue(":city", "Санкт-Петербург");
        query.bindValue(":cost", 5394);
    if (! query.exec()) {
        _log.warning("Ошибка заполнения 0 таблица city_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO city_cost (id,city,cost) VALUES (:id,:city,:cost)");
        query.bindValue(":id", 1);
        query.bindValue(":city", "Москва");
        query.bindValue(":cost", 6457);
    if (! query.exec()) {
        _log.warning("Ошибка заполнения 1 таблица city_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO city_cost (id,city,cost) VALUES (:id,:city,:cost)");
        query.bindValue(":id", 2);
        query.bindValue(":city", "Стамбул");
        query.bindValue(":cost", 9771);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 2 таблица city_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO city_cost (id,city,cost) VALUES (:id,:city,:cost)");
        query.bindValue(":id", 3);
        query.bindValue(":city", "Каппадоккия");
        query.bindValue(":cost", 8976);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 3 таблица city_cost. " + query.lastError().text());
    }

    query.prepare("CREATE TABLE IF NOT EXISTS hotel_cost("
                  "id INTEGER PRIMARY KEY, "
                  "hotel TEXT  , "
                  "cost INTEGER)");
    if (! query.exec()) {
            _log.warning("Ошибка создания таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 0);
        query.bindValue(":hotel", "Октябрьская");
        query.bindValue(":cost", 5750);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 0 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 1);
        query.bindValue(":hotel", "Wawelberg");
        query.bindValue(":cost", 30000);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 1 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 2);
        query.bindValue(":hotel", "Ибис");
        query.bindValue(":cost", 6050);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 2 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 3);
        query.bindValue(":hotel", "А.Kosterev");
        query.bindValue(":cost", 4320);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 3 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 4);
        query.bindValue(":hotel", "Akgun Istanbul");
        query.bindValue(":cost", 5272);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 4 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 5);
        query.bindValue(":hotel", "Ibis");
        query.bindValue(":cost", 3723);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 5 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 6);
        query.bindValue(":hotel", "Cappadocia Caves");
        query.bindValue(":cost", 14931);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 6 таблица hotel_cost. " + query.lastError().text());
    }

    query.prepare("REPLACE INTO hotel_cost(id,hotel,cost) VALUES (:id,:hotel,:cost)");
        query.bindValue(":id", 7);
        query.bindValue(":hotel", "Kemal stone house");
        query.bindValue(":cost", 2550);
    if (! query.exec()) {
            _log.warning("Ошибка заполнения 7 таблица hotel_cost. " + query.lastError().text());
    }
}
