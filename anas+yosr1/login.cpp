#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTextLength>
#include "menu.h"
#include "mainwindow_Bagage.h"
#include "ui_menu.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_login_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString user ;
    QString pswd ;
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from LOGIN where USERNAME= :username");
    test.bindValue(":username",username);
    test.exec();
    if (test.next())
    {
    if (test.value(0).toInt() == 1)
    {
    QSqlQuery query ;
    query.prepare("SELECT USERNAME,PASSWORD FROM LOGIN WHERE USERNAME= :username");
    query.bindValue(":username",username);
    query.exec();
    if (query.next())
    {
    user = query.value(0).toString();
    pswd = query.value(1).toString();
    if (username == user && password == pswd)
    {
        QStringList myOptions;
        myOptions << "yosr" << "anas" << "amir" << "aziz" <<"nessrin"<<"ayoub"<< "admin";
        switch(myOptions.indexOf(user))
        {
          case 0:
            hide();

                    m.show();
                    m.ui->gestionBagage->setEnabled(false);
                    m.ui->gestionVol->setEnabled(false);
                    m.ui->gestionBillet->setEnabled(false);
                    m.ui->gestionAvion->setEnabled(false);
                    m.ui->gestionEmployee->setEnabled(false);
            break;
          case 1:
            hide();

                   m.show();
                   m.ui->gestionPasager->setEnabled(false);
                   m.ui->gestionVol->setEnabled(false);
                   m.ui->gestionBillet->setEnabled(false);
                   m.ui->gestionAvion->setEnabled(false);
                   m.ui->gestionEmployee->setEnabled(false);
            break;
        case 2 :
            hide();
                   m.show();
                   m.ui->gestionBagage->setEnabled(false);
                   m.ui->gestionPasager->setEnabled(false);
                   m.ui->gestionVol->setEnabled(false);
                   m.ui->gestionBillet->setEnabled(false);
                   m.ui->gestionEmployee->setEnabled(false);

            break ;
        case 3 :
            hide();
                   m.show();
                   m.ui->gestionBagage->setEnabled(false);
                   m.ui->gestionPasager->setEnabled(false);
                   m.ui->gestionVol->setEnabled(false);
                   m.ui->gestionBillet->setEnabled(false);
                   m.ui->gestionAvion->setEnabled(false);
            break ;
        case 4 :
            hide();
                    m.show();
                    m.ui->gestionBagage->setEnabled(false);
                    m.ui->gestionPasager->setEnabled(false);
                    m.ui->gestionEmployee->setEnabled(false);
                    m.ui->gestionAvion->setEnabled(false);
                    m.ui->gestionBillet->setEnabled(false);
            break ;
        case 5 :
            hide();
                   m.show();
                   m.ui->gestionBagage->setEnabled(false);
                   m.ui->gestionPasager->setEnabled(false);
                   m.ui->gestionEmployee->setEnabled(false);
                   m.ui->gestionAvion->setEnabled(false);
                   m.ui->gestionVol->setEnabled(false);

            break ;
        case 6 :
            m.show();
            break ;
    }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INCORRECT USERNAME OR PASSWORD.\nCLICK CANCEL TO RETURN."), QMessageBox::Ok);
    }
    }
    }
}}
