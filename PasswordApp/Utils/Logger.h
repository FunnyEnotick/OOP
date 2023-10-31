#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDateTime>

class Logger
{
    QString getCurrentDateTime();
public:
    void info(const QString &message);
    void debug(const QString &message);
    void warning(const QString &message);
    void error(const QString &message);
};

#endif // LOGGER_H
