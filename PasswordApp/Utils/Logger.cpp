#include "Logger.h"


QString Logger::getCurrentDateTime()
{
    return QDateTime::currentDateTime().toString("dd.MM.yy HH:mm:ss");
}

void Logger::info(const QString &message)
{
    qDebug() << "[INFO] --" << getCurrentDateTime() << "--" << message;
}

void Logger::debug(const QString &message)
{
    qDebug() << "[DEBUG] --" << getCurrentDateTime() << "--" << message;
}

void Logger::warning(const QString &message)
{
    qDebug() << "[WARNING] --" << getCurrentDateTime() << "--" << message;
}

void Logger::error(const QString &message)
{
    qDebug() << "[ERROR] --" << getCurrentDateTime() << "--" << message;
}
