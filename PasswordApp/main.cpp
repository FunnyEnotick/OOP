#include "LoginWindow.h"

#include <QApplication>
#include "Utils/DatabaseManager.h"

static const QString dbName = "New4DB.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager *database = DatabaseManager::getInstance();

    database->connect(dbName);
    database->createTables();
    LoginWindow w;
    w.setWindowTitle("Password Application");
    w.show();
    return a.exec();
}
