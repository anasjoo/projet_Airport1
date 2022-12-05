#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include "qdebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    Login l;
    bool test=c.createconnect();
    if(test)
    {
        l.show();

          qDebug()<<"database open";
}
    else
      qDebug()<<"database not open";

    return a.exec();
}
