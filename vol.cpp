#include "vol.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Vol::Vol()
{
ID_VOL=0;
DIRECTION="";
DATE_VOL="";
}

Vol::Vol (int ID_VOL, QString DIRECTION,QString DATE_VOL)
{
    this->ID_VOL=ID_VOL;
    this->DIRECTION=DIRECTION;
    this->DATE_VOL=DATE_VOL;
}
int Vol::getID_VOL()
{
    return ID_VOL;
}
QString Vol::getDIRECTION()
{
    return DIRECTION;
}
QString Vol::getDATE_VOL()
{
    return DATE_VOL;
}
void Vol::setID_VOL(int ID_VOL)
{
    this->ID_VOL=ID_VOL;
}
void Vol::setDIRECTION(QString DIRECTION)
{
    this->DIRECTION=DIRECTION;
}
void Vol::setDATE_VOL(QString DATE_VOL)
{
    this->DATE_VOL=DATE_VOL;
}
bool Vol::ajouter()
{


    QSqlQuery query;
    QString ID_string=QString::number(ID_VOL);
    query.prepare("INSERT INTO Vol (ID_VOL, DIRECTION, DATE_VOL) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id",ID_string);
    query.bindValue(":direction",DIRECTION );
    query.bindValue(":date du vol", DATE_VOL);
    return query.exec();


}
QSqlQueryModel* Vol::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT* FROM Vol");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOL"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("DIRECTION"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_VOL"));
  return model;
}
bool Vol::supprimer(int ID_VOL)
{
    QSqlQuery query ;
    query.prepare("DELETE from vol where ID_VOL=:ID") ;
    query.bindValue(0,ID_VOL);
    return query.exec();
}
