#include "connection.h"
#include"mainwindow.h"
#include <QApplication>
#include <QMessageBox>

connection::connection()
{

}
bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("SMART_AIRPORT");
    db.setUserName("Nesrine");
    db.setPassword("esprit18");
    if (db.open()) test=true;
    return test;
}
void connection::closeConnection()
{
    db.close();
}
