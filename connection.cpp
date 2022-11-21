#include "connection.h"

Connection::Connection(){}


bool Connection::createConnection()
{
    db =QSqlDatabase:: addDatabase ("QODBC");
    bool test=false;
db.setDatabaseName("Projet2A");
db.setUserName("Yosr");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;


    return  test;
}
void Connection:: closeConnection(){db.close();}
