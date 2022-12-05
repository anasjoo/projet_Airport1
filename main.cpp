#include "mainwindow_Bagage.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
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
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
