#include "connection.h"


//git


Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("amir");
db.setPassword("esprit36");

if (db.open()) test=true;

    return  test;
}

void Connection::closeConnection() {db.close();}



