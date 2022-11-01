#include "vol.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Vol::Vol()
{
ID_VOL=0;
DIRECTION="";
ARRIVE_VOL="";
DEPART_VOL="";

}

Vol::Vol (int ID_VOL, QString DIRECTION,QString ARRIVE_VOL,QString DEPART_VOL)
{
    this->ID_VOL=ID_VOL;
    this->DIRECTION=DIRECTION;
    this->ARRIVE_VOL=ARRIVE_VOL;
    this->DEPART_VOL=DEPART_VOL;
}
int Vol::getID_VOL()
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
void Vol::setID_VOL(int ID_VOL)
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
    QString ID_string=QString::number(ID_VOL);
    query.prepare("INSERT INTO Vol (ID_VOL, DIRECTION, DEPART_VOL,ARRIVE_VOL) "
                  "VALUES (:ID_VOL, :DIRECTION, :DEPART_VOL, :ARRIVE_VOL)");
    query.bindValue(":ID_VOL",ID_string);
    query.bindValue(":DIRECTION",DIRECTION );
    query.bindValue(":ARRIVE_VOL", ARRIVE_VOL);
    query.bindValue(":DEPART_VOL", DEPART_VOL);
    return query.exec();


}
QSqlQueryModel* Vol::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT* FROM Vol");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOL"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("DIRECTION"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPART_VOL"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("ARRIVE_VOL"));
  return model;
}
bool Vol::supprimer(int ID_VOL)
{
    QSqlQuery query ;
    query.prepare("DELETE from vol where ID_VOL=:ID_VOL") ;
    query.bindValue(":ID_VOL", ID_VOL);
    return query.exec();
}
bool Vol::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE Vol SET ID_VOL= :ID_VOL,DIRECTION= :DIRECTION,DEPART_DATE= :DEPART_DATE");
    query.bindValue(":ID_VOL",ID_VOL);
    query.bindValue(":DIRCTION",DIRECTION);
    query.bindValue(":DEPART_VOL",DEPART_VOL);
    query.bindValue(":ARRIVE_DEPART",ARRIVE_VOL);
    return query.exec();

}
