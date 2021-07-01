#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QSqlQueryModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createConnection();
    MainWindow w;
     w.show();
      return a.exec();

    if(!createConnection())
        return 1;
    if(!createTables())
        return 1;
}
