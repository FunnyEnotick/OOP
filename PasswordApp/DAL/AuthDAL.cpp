#include "AuthDAL.h"
#include "../Exceptions/UserNotFound.h"
#include "../Exceptions/BadRequest.h"
#include <QDebug>

AuthDAL::AuthDAL()
{
    _baseQuery = "SELECT login, password, is_admin FROM users ";
}

QPair<QString, QString> AuthDAL::findUserByLogin(const QString &login)
{
    QSqlQuery query;
    query.prepare(_baseQuery + "WHERE login = :login");
    query.bindValue(":login", login);
    query.exec();
    if (query.next()) {
        QPair<QString, QString> admin;
        admin.first = QString(query.value(0).toString());
        admin.second = QString(query.value(1).toString());
        return admin;
    } else {
        throw UserNotFound("Администратор [" + login + "] не найден" + query.lastError().text());
    }
}

void AuthDAL::addAdmin(const QString &login, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (login, password, is_admin) VALUES (:login, :password, 1)");
    query.bindValue(":login", login);
    query.bindValue(":password", hashPassword(password));
    if (! query.exec()) {
        throw BadRequest("Ошибка добавления администратора [" + login + "]. Запрос: " + query.lastError().text());
    }
}

QString AuthDAL::hashPassword(const QString &password)
{
    QByteArray hp = password.toUtf8();
    return QString(QCryptographicHash::hash(hp, QCryptographicHash::Sha256).toHex());
}
