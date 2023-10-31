#ifndef AUTHDALINTERFACE_H
#define AUTHDALINTERFACE_H

#include <QPair>
#include <QString>

struct AuthDALInterface {
    virtual QPair<QString, QString> findUserByLogin(const QString &login) = 0;
    virtual void addAdmin(const QString &login, const QString &password) = 0;
    virtual QString hashPassword(const QString &password) = 0;
    virtual ~AuthDALInterface(){};
};

#endif // AUTHDALINTERFACE_H
