#ifndef GESTION_VOL_H
#define GESTION_VOL_H
# include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QAbstractItemModel>
//#include "mainwindow.h"
//#include "ui_mainwindow.h"

class gestion_vol
{
public:
    gestion_vol();
    gestion_vol (QString, QString,QString,QString);
    QString  getID_VOL();
    QString getDIRECTION();
    QString getARRIVE_VOL();
    QString getDEPART_VOL();
    void setID_VOL(QString);
    void setDIRECTION(QString);
    void setARRIVE_VOL(QString);
    void setDEPART_VOL(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier (QString);
    QSqlQueryModel * rechercher(QString);
     QSqlQueryModel *tri();
     QSqlQueryModel * trid();
     bool modifier_emploi(QString ID_VOL, QString DEPART_VOL, QString ARRIVE_VOL);

     bool ajouterMessage(QString);
     QSqlQueryModel * afficherMessage();
QString ARRIVE_VOL,DEPART_VOL,ID_VOL, DIRECTION;
};

#endif // GESTION_VOL_H
