#ifndef AUTHDAL_H
#define AUTHDAL_H

#include <QSqlQuery>
#include <QPair>
#include <QString>
#include <QSqlError>
#include <QCryptographicHash>

#include "AuthDALInterface.h"

class AuthDAL : public AuthDALInterface
{
public:
    AuthDAL();
    QPair<QString, QString> findUserByLogin(const QString &login) override;
    void addAdmin(const QString &login, const QString &password) override;
    QString hashPassword(const QString &password) override;
private:
    QString _baseQuery;
};

#endif // AUTHDAL_H
