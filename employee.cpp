#include "employee.h"
#include <QSqlQuery>
#include <QObject>

Employee::Employee()
{
id=0;nom=" ";prenom=" ";fonction=" ";
}
Employee::Employee(int id,QString nom , QString prenom  , QString  fonction)
{this->nom=nom;this->prenom=prenom;this->id=id;this->fonction=fonction;}
QString Employee::getnom(){return nom;}
QString Employee::getprenom(){return prenom;}
int Employee::getid(){return id;}
void Employee::setnom (QString nom){this->nom=nom;}
void Employee::setprenom (QString prenom){this->prenom=prenom;}
void Employee::setfonction(QString fonction){this->fonction=fonction;}
void Employee::setid(int id){this->id=id;}

bool Employee::ajouter()
{
    QSqlQuery query;
     // QString id_string=QString::number(id);

           query.prepare("INSERT INTO EMPLOYES (id,nom,prenom,fonction ) "
                         "VALUES (:ID,:NOM, :PRENOM, :FONCTION)");
           query.bindValue(":ID", id);
           query.bindValue(":NOM", nom);
           query.bindValue(":PRENOM", prenom);
           query.bindValue(":FONCTION",fonction);


           return query.exec();
}
QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT id,nom,prenom,fonction FROM EMPLOYES");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal ,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));


    return model;
}
bool Employee::supprimer(int id )
{   QSqlQuery query;


         query.prepare("delete from employes where id=:id");
         query.bindValue(0, id);


         return query.exec();

}
bool Employee::modifier()
{
    QSqlQuery query;
     // QString id_string=QString::number(id);

           query.prepare("update EMPLOYES set nom=:NOM,prenom=:PRENOM,fonction=:FONCTION where id=:ID ");
           query.bindValue(":ID", id);
           query.bindValue(":NOM", nom);
           query.bindValue(":PRENOM", prenom);
           query.bindValue(":FONCTION",fonction );


           return query.exec();
}
QSqlQueryModel * Employee::tri()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,fonction FROM EMPLOYES ORDER BY CAST(id AS number)");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));

    return model;
}
QSqlQueryModel * Employee::tri1()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,fonction FROM EMPLOYES ORDER BY NOM ASC");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));

    return model;
}
QSqlQueryModel * Employee::tri2()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id,nom,prenom,fonction FROM EMPLOYES ORDER BY prenom ASC");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));
    return model;
}
QSqlQuery Employee::request(QString code)
{
    QSqlQuery query;
    query.prepare("select CARTE from EMPLOYES where CARTE= '"+code+"'");
    query.addBindValue(code);
    query.exec();
    return query;
}
