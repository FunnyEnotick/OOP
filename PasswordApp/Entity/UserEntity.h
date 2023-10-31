#ifndef USERENTITY_H
#define USERENTITY_H

#include <QString>

class UserEntity
{
    QString _name;
    QString _email;
    QString _phoneNumber;
public:
    UserEntity(const QString& name, const QString& email, const QString &phoneNumber)
        : _name(name), _email(email), _phoneNumber(phoneNumber){}
};

#endif // USERENTITY_H
