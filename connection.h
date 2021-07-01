#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

inline bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("rks1");
    db.setUserName("postgres");
    db.setPassword("123");

    if (!db.open())
    {
        QMessageBox::warning(NULL,QObject::tr("Ошибка"),db.lastError().text());
        return false;
    }

    else
    {
        QMessageBox::information(NULL, "Завершено", "Соединение с базой данных успешно");
        return true;
    }
}

inline bool createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE USERS("
                "IdUser INTEGER PRIMARY KEY AUTOINCREMENT, "
                "FirstName NVARCHAR(30) NOT NULL,"
                "LastName NVARCHAR(30) NOT NULL,"
                "Number INTEGER NOT NULL)");
    return(1);

    QSqlQuery query1;
    query.exec("CREATE TABLE FILE("
                "IdFile INTEGER PRIMARY KEY AUTOINCREMENT,"
                "Name character NVARCHAR(100) NOT NULL,"
                "Size(kb)  INTEGER NOT NULL,"
                "Location NVARCHAR(255) NOT NULL,"
                "IdUser INTEGER NOT NULL)");
     return(1);
}

#endif // CONNECTION_H
