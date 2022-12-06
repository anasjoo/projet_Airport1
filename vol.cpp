#include "vol.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QString>
Vol::Vol()
{
ID_VOL="";
DIRECTION="";
ARRIVE_VOL="";
DEPART_VOL="";

}

Vol::Vol (QString ID_VOL,QString ARRIVE_VOL,QString DEPART_VOL, QString DIRECTION)
{
    this->ID_VOL=ID_VOL;
    this->ARRIVE_VOL=ARRIVE_VOL;
    this->DEPART_VOL=DEPART_VOL;
    this->DIRECTION=DIRECTION;
}
QString Vol::getID_VOL()
{
    return ID_VOL;
}
QString Vol::getDIRECTION()
{
    return DIRECTION;
}
QString Vol::getARRIVE_VOL()
{
    return ARRIVE_VOL;
}
QString Vol::getDEPART_VOL()
{
    return DEPART_VOL;
}
void Vol::setID_VOL(QString ID_VOL)
{
    this->ID_VOL=ID_VOL;
}
void Vol::setDIRECTION(QString DIRECTION)
{
    this->DIRECTION=DIRECTION;
}
void Vol::setARRIVE_VOL(QString ARRIVE_VOL)
{
    this->ARRIVE_VOL=ARRIVE_VOL;
}
void Vol::setDEPART_VOL(QString DEPART_VOL)
{
    this->DEPART_VOL=DEPART_VOL;
}
bool Vol::ajouter()
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
QSqlQueryModel* Vol::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT* FROM VOL");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOL"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPART_VOL"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("ARRIVE_VOL"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DIRECTION"));
  return model;
}
bool Vol::supprimer(QString ID_VOL)
{
    QSqlQuery query ;
    query.prepare("DELETE from VOL where ID_VOL=:ID_VOL") ;
    query.bindValue(":ID_VOL",ID_VOL);
    return query.exec();
}
bool Vol::modifier(QString ID_VOL)
{
    QSqlQuery query;

    query.prepare("UPDATE VOL SET ID_VOL=:ID_VOL,ARRIVE_VOL=:ARRIVE_VOL,DEPART_VOL=:DEPART_VOL,DIRECTION=:DIRECTION WHERE ID_VOL=:ID_VOL");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":DEPART_VOL",DEPART_VOL);
    query.bindValue(":ARRIVE_VOL",ARRIVE_VOL);
    query.bindValue(":DIRECTION",DIRECTION);


    return query.exec();

}
QSqlQueryModel *Vol::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from VOL where ID_VOL LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *Vol::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM VOL ORDER BY DIRECTION ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *Vol::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM VOL ORDER BY DIRECTION DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}
bool Vol::modifier_emploi(QString ID_VOL, QString DEPART_VOL, QString ARRIVE_VOL)
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

bool Vol::ajouterMessage(QString ID_VOL )
{
    QSqlQuery query;
    query.prepare("UPDATE Vol SET DIRECTION=:DIRECTION WHERE ID_VOL=:ID_VOL");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":DIRECTION",DIRECTION);
    return query.exec();
}

QSqlQueryModel * Vol::afficherMessage(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT ID_VOL,DIRECTION FROM Vol where ID_VOL IS NOT NULL ");


    return model;

}
