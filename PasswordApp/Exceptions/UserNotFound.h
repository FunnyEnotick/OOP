#ifndef USERNOTFOUND_H
#define USERNOTFOUND_H

#include <QString>

class UserNotFound {
  QString _message;
public:
  UserNotFound(const QString &msg) : _message(msg){}
  QString what() const {return "Пользователь не найден. Исключение: " + _message; }
};
#endif // USERNOTFOUND_H
