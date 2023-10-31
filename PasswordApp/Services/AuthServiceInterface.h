#ifndef AUTHSERVICEINTERFACE_H
#define AUTHSERVICEINTERFACE_H

#include <QString>

struct AuthServiceInterface {
    virtual bool isExistUser(const QString &login, const QString &password) = 0;
    virtual bool addAdmin(const QString &login, const QString &password) = 0;
    virtual ~AuthServiceInterface(){};
};

#endif // AUTHSERVICEINTERFACE_H
