#include "avion.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QTableView>

avion::avion()
{}
avion::avion(QString id,QString nom ,QString salaire,QString heurepayee, QString note , QString heuresup)
{
    this->id=id;
    this->nom=nom;
    this->salaire=salaire;
    this->heurepayee=heurepayee;
    this->note=note;
    this->heuresup=heuresup;
}



bool avion::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO AVION (ID,NOM,SALAIRE,HEUREPAYEE,NOTE,HEURESUP) "
                        "VALUES (:ID, :NOM, :SALAIRE,:HEUREPAYEE,:NOTE,:HEURESUP)");
    // l'éxecution du requete !!
          query.bindValue(":ID", id);
          query.bindValue(":NOM", nom);
          query.bindValue(":SALAIRE", salaire);
          query.bindValue(":HEUREPAYEE", heurepayee);
          query.bindValue(":NOTE", note);
          query.bindValue(":HEURESUP", heuresup);
        return  query.exec();
}





bool avion::modifier()
{
    QSqlQuery query;

query.prepare("UPDATE AVION SET ID='"+id+"',NOM='"+nom+"',SALAIRE='"+salaire+"',HEUREPAYEE='"+heurepayee+"',NOTE='"+note+"',HEURESUP='"+heuresup+"' WHERE ID='"+id+"' ");

     query.bindValue(0,id);
     query.bindValue(1,nom);
     query.bindValue(2,salaire);
     query.bindValue(3,heurepayee);
     query.bindValue(4,note );
     query.bindValue(5,heuresup);

      return query.exec();
}


QSqlQueryModel *avion::trieravion()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM AVION ORDER BY HEUREPAYEE ASC");
        return model;

}

QSqlQueryModel *avion ::recherche(QString id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM AVION WHERE ID LIKE '%"+id+"%' ");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("SALAIRE"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEUREPAYEE"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOTE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("HEURESUP"));
     return model;
 }
bool avion ::supprimer(QString id)
 {
     QSqlQuery query;
     //QString res=QString::n(id);
     query.prepare("Delete from AVION where ID=:id");
     query.bindValue(":id",id);
     return query.exec();
 }
QString avion::getid(){return id;}
QString avion::getnom(){return nom;}
QString avion::getsalaire(){return salaire;}
QString avion::getheurepayee(){return heurepayee;}
QString avion::getnote(){return note;}
QString avion::getheuresup(){return heuresup;}

void avion::setid(QString id){this ->id=id;}
void avion::setnom(QString nom){this ->nom=nom;}
void avion::setsalaire(QString salaire){this ->salaire=salaire;}
void avion::setheurepayee(QString heurepayee){this ->heurepayee=heurepayee;}
void avion::setnote(QString note){this ->note=note;}
void avion::setheuresup(QString heuresup){this ->heuresup=heuresup;}
