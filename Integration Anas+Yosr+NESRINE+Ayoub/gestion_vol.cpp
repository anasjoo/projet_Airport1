#include "gestion_vol.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QString>
gestion_vol::gestion_vol()
{
ID_VOL="";
DIRECTION="";
ARRIVE_VOL="";
DEPART_VOL="";

}

gestion_vol::gestion_vol (QString ID_VOL,QString ARRIVE_VOL,QString DEPART_VOL, QString DIRECTION)
{
    this->ID_VOL=ID_VOL;
    this->ARRIVE_VOL=ARRIVE_VOL;
    this->DEPART_VOL=DEPART_VOL;
    this->DIRECTION=DIRECTION;
}
QString gestion_vol::getID_VOL()
{
    return ID_VOL;
}
QString gestion_vol::getDIRECTION()
{
    return DIRECTION;
}
QString gestion_vol::getARRIVE_VOL()
{
    return ARRIVE_VOL;
}
QString gestion_vol::getDEPART_VOL()
{
    return DEPART_VOL;
}
void gestion_vol::setID_VOL(QString ID_VOL)
{
    this->ID_VOL=ID_VOL;
}
void gestion_vol::setDIRECTION(QString DIRECTION)
{
    this->DIRECTION=DIRECTION;
}
void gestion_vol::setARRIVE_VOL(QString ARRIVE_VOL)
{
    this->ARRIVE_VOL=ARRIVE_VOL;
}
void gestion_vol::setDEPART_VOL(QString DEPART_VOL)
{
    this->DEPART_VOL=DEPART_VOL;
}
bool gestion_vol::ajouter()
{


    QSqlQuery query;

    query.prepare("INSERT INTO Vol (ID_VOL,ARRIVE_VOL,DEPART_VOL,DIRECTION) "
                  "VALUES (:ID_VOL,:ARRIVE_VOL, :DEPART_VOL, :DIRECTION)");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":ARRIVE_VOL", ARRIVE_VOL);
    query.bindValue(":DEPART_VOL", DEPART_VOL);
    query.bindValue(":DIRECTION",  DIRECTION );
    return query.exec();


}
QSqlQueryModel* gestion_vol::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT* FROM VOL");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOL"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPART_VOL"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("ARRIVE_VOL"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DIRECTION"));
  return model;
}
bool gestion_vol::supprimer(QString ID_VOL)
{
    QSqlQuery query ;
    query.prepare("DELETE from VOL where ID_VOL=:ID_VOL") ;
    query.bindValue(":ID_VOL",ID_VOL);
    return query.exec();
}
bool gestion_vol::modifier(QString ID_VOL)
{
    QSqlQuery query;

    query.prepare("UPDATE VOL SET ID_VOL=:ID_VOL,ARRIVE_VOL=:ARRIVE_VOL,DEPART_VOL=:DEPART_VOL,DIRECTION=:DIRECTION WHERE ID_VOL=:ID_VOL");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":DEPART_VOL",DEPART_VOL);
    query.bindValue(":ARRIVE_VOL",ARRIVE_VOL);
    query.bindValue(":DIRECTION",DIRECTION);


    return query.exec();

}
QSqlQueryModel *gestion_vol::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from VOL where ID_VOL LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *gestion_vol::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM VOL ORDER BY DIRECTION ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *gestion_vol::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM VOL ORDER BY DIRECTION DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}
bool gestion_vol::modifier_emploi(QString ID_VOL, QString DEPART_VOL, QString ARRIVE_VOL)
{
   QSqlQuery query;
    DEPART_VOL=("d MMM yyyy h:m");
    ARRIVE_VOL=("d MMM yyyy h:m");
    QString date_string = DEPART_VOL + ARRIVE_VOL;

    query.prepare("UPDATE VOL set ARRIVE_VOL=:reserv where ID_VOL=:ID_VOL");
    query.bindValue(":ID_VOL", ID_VOL);
    query.bindValue(":reserv", date_string);

    return query.exec();
}

bool gestion_vol::ajouterMessage(QString ID_VOL )
{
    QSqlQuery query;
    query.prepare("UPDATE Vol SET DIRECTION=:DIRECTION WHERE ID_VOL=:ID_VOL");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":DIRECTION",DIRECTION);
    return query.exec();
}

QSqlQueryModel * gestion_vol::afficherMessage(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT ID_VOL,DIRECTION FROM Vol where ID_VOL IS NOT NULL ");


    return model;

}
