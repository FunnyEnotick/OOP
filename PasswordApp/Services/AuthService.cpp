#include "AuthService.h"
#include "../Exceptions/UserNotFound.h"
#include "../Exceptions/BadRequest.h"


bool AuthService::isExistUser(const QString &login, const QString &password)
{
    QString hashPassword = _authDAL->hashPassword(password);
    QPair<QString, QString> admin;
    try {
        admin = _authDAL->findUserByLogin(login);
    } catch (UserNotFound &e) {
        _log.warning(e.what());
        return false;
    }
    if (admin.first == login && admin.second == hashPassword) {
        return true;
    } else {
        return false;
    }
}

bool AuthService::addAdmin(const QString &login, const QString &password)
{
    try {
        _authDAL ->addAdmin(login, password);
        _log.debug("Администратор [" + login + "] добавлен");
        return true;
    } catch (BadRequest &e) {
        _log.warning(e.what());
        return false;
    }
}
