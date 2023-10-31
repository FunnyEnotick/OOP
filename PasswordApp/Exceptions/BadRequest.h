#ifndef BADREQUEST_H
#define BADREQUEST_H

#include <QString>

class BadRequest {
    QString _message;
public:
    BadRequest(const QString &msg) : _message(msg){};
    QString what() const { return "Ошибка запроса. Исключение: " + _message;}
};

#endif // BADREQUEST_H
