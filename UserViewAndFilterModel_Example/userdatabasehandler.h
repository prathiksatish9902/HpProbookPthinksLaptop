#ifndef USERDATABASEHANDLER_H
#define USERDATABASEHANDLER_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "user.h"

class UserDatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit UserDatabaseHandler(QObject *parent = nullptr);
    ~UserDatabaseHandler();

    static QList<User*> loadUserFromDb();

signals:
};

#endif // USERDATABASEHANDLER_H
