#include <QCoreApplication>
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseHandler dbHandler;

    if (dbHandler.connectToDatabase()) {
        dbHandler.insertEmployee();
        dbHandler.showAllEmployees();
    }

    return a.exec();
}
