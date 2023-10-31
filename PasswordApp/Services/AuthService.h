#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QScopedPointer>
#include <QString>
#include <QPair>

#include "../Utils/Logger.h"
#include "AuthServiceInterface.h"
#include "../DAL/AuthDAL.h"

class AuthService : public AuthServiceInterface
{
    Logger _log;
    QScopedPointer<AuthDALInterface> _authDAL;
public:
    AuthService() : _authDAL(new AuthDAL){};
    bool isExistUser(const QString &login, const QString &password) override;
    bool addAdmin(const QString &login, const QString &password) override;
};

#endif // AUTHSERVICE_H
