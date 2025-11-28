#include "userdatabasehandler.h"

UserDatabaseHandler::UserDatabaseHandler(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;
}

UserDatabaseHandler::~UserDatabaseHandler()
{
    qDebug()<<Q_FUNC_INFO;
}

QList<User*> UserDatabaseHandler::loadUserFromDb()
{
    qDebug()<<Q_FUNC_INFO;
    QList<User*> users;

    const QString connName = QStringLiteral("UserDBConnection");
    if (QSqlDatabase::contains(connName))
        QSqlDatabase::removeDatabase(connName);

    QSqlDatabase db = QSqlDatabase::addDatabase(QStringLiteral("QPSQL"), connName);
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("UserManagement");
    db.setUserName("prathiksatish7135");
    db.setPassword("prathik9902@@@");

    if (!db.open()) {
        qWarning() << "Failed to open DB:" << db.lastError().text();
        QSqlDatabase::removeDatabase(connName);
        return users;
    }

    const QString sql = QStringLiteral("SELECT name, user_role, user_id, password FROM users");
    {
        QSqlQuery query(db);
        if (!query.exec(sql)) {
            qWarning() << "Query failed:" << query.lastError().text();
            db.close();
            QSqlDatabase::removeDatabase(connName);
            return users;
        }

        while (query.next())
        {
            User* u = new User(
                query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString()
                );
            users.append(u);
        }
    }

    db.close();
    QSqlDatabase::removeDatabase(connName);
    return users;
}
