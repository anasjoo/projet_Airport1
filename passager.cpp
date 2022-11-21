#include "passager.h"
#include<QtDebug>
#include <QObject>
Passager :: Passager(int CIN, int Tel, QString nom, QString prenom, QString destination, QDate date_naissance,QString sexe)
{
    this->CIN=CIN;
    this->Tel=Tel;
    this->nom= nom;
    this->prenom=prenom;
    this->destination=destination;
    this->date_naissance=date_naissance;
    this->sexe=sexe;


}

bool Passager:: ajouter()
{

  QSqlQuery query;
  QString res=QString::number(CIN);
        query.prepare("INSERT INTO PASSAGERS (ID_PASSAGER, TEL,NOM,PRENOM,DESTINATION,DATE_NAISSANCE,SEXE) "
                      "VALUES (:ID_PASSAGER, :TEL, :NOM,:PRENOM,:DESTINATION,:DATE_NAISSANCE,:SEXE)");
        query.bindValue(":ID_PASSAGER", res);
        query.bindValue(":TEL",Tel);
        query.bindValue(":NOM", nom);
        query.bindValue(":PRENOM", prenom);
        query.bindValue(":DESTINATION", destination);
        query.bindValue(":DATE_NAISSANCE", date_naissance);
        query.bindValue(":SEXE", sexe);

        return query.exec();

}
 QSqlQueryModel* Passager:: afficher()
 {
QSqlQueryModel*model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM PASSAGERS");
      model->setHeaderData(0, Qt::Horizontal, QObject:: tr("ID_PASSAGER"));
      model->setHeaderData(1, Qt::Horizontal, QObject ::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject ::tr("TEL"));
      model->setHeaderData(3, Qt::Horizontal, QObject ::tr("DESTINATION"));
      model->setHeaderData(4, Qt::Horizontal, QObject ::tr("DATE_NAISSANCE"));
      model->setHeaderData(5, Qt::Horizontal, QObject ::tr("PRENOM"));
      model->setHeaderData(6, Qt::Horizontal, QObject ::tr("SEXE"));




return model;

 }

 bool Passager :: supprimer(int CIN)
 {
     QSqlQuery query;
     QString res=QString::number(CIN);
     query.prepare("Delete from PASSAGERS where ID_PASSAGER=:CIN");
     query.bindValue(":CIN",res);
     return query.exec();
 }


 bool Passager::modifier(int CIN, int Tel, QString nom, QString prenom, QString destination, QDate date_naissance)
   {
     QSqlQuery query;
      QString res=QString::number(CIN);
     query.prepare("update PASSAGERS set  ID_PASSAGER=:ID_PASSAGER, TEL=:TEL,NOM=:NOM,PRENOM=:PRENOM,DESTINATION=:DESTINATION,DATE_NAISSANCE=:DATE_NAISSANCE,SEXE=:SEXE Where ID_PASSAGER=:ID_PASSAGER  ");



     query.bindValue(":ID_PASSAGER", res);
     query.bindValue(":TEL",Tel);
     query.bindValue(":NOM", nom);
     query.bindValue(":PRENOM", prenom);
     query.bindValue(":DESTINATION", destination);
     query.bindValue(":DATE_NAISSANCE", date_naissance);
     query.bindValue(":SEXE", sexe);


     return query.exec();
 }


 QSqlQueryModel *Passager ::rechercher(QString CIN)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM PASSAGERS WHERE ID_PASSAGER LIKE '%"+CIN+"%' ");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PASSAGER"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEL"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRENOM"));
     return model;
 }

 QSqlQueryModel * Passager::afficher_P_trie_des()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM PASSAGERS ORDER BY DESTINATION ;");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PASSAGER"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEL"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRENOM"));
     return model;
 }
 QSqlQueryModel* Passager::afficher_P_trie_date(){

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM PASSAGERS ORDER BY DATE_NAISSANCE ;");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PASSAGER"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEL"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRENOM"));
     return model;


 }


