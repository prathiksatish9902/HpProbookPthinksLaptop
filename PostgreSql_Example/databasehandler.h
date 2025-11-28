#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseHandler : public QObject
{
    Q_OBJECT

public:
    DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();

    bool connectToDatabase();
    void insertEmployee();
    void showAllEmployees();

private:
    QSqlDatabase db;
};
#endif // DATABASEHANDLER_H
