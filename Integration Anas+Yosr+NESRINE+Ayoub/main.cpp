#include "mainwindow_Bagage.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include "qdebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login l;
    Connection c;
     //MainWindow w;
    bool test=c.createconnect();
    // MainWindow w;
    if(test)
        // MainWindow w;
    {
        l.show();

          qDebug()<<"database open";
}
    else
      qDebug()<<"database not open";

    return a.exec();
}
