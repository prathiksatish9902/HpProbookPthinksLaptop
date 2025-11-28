#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
}

DatabaseHandler::~DatabaseHandler()
{
    qDebug()<<Q_FUNC_INFO;
}

bool DatabaseHandler::connectToDatabase()
{
    qDebug()<<Q_FUNC_INFO;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("postgres");
    db.setUserName("prathiksatish7135");
    db.setPassword("prathik9902@@@");

    if(!db.open())
    {
        qDebug()<<"connection failed"<<db.lastError().text();
        return false;
    }

    qDebug()<<"connection success";
    return true;
}

void DatabaseHandler::insertEmployee()
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (Emp_No , Emp_Name , Emp_Add , Emp_Phone , Dept_No , Dept_Name , Salary)"
                  "VALUES (:no , :name , :add , :phone , :dno , :dname , :salary)");
    query.bindValue(":no" , 111);
    query.bindValue(":name" , "Rohit");
    query.bindValue(":add" , "HSR Layout");
    query.bindValue(":phone" , "9988776655");
    query.bindValue(":dno", "D02");
    query.bindValue(":dname", "HR");
    query.bindValue(":salary", "60000");

    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
    }
    else {
        qDebug() << "Row inserted successfully!";
    }
}

void DatabaseHandler::showAllEmployees()
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery query("SELECT * FROM employee");
    while (query.next()) {
        qDebug() << "Emp_No:" << query.value("Emp_No").toInt()
        << "Name:" << query.value("Emp_Name").toString()
        << "Dept:" << query.value("Dept_Name").toString()
        << "Salary:" << query.value("Salary").toString();
    }
}
