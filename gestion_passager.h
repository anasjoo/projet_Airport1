#ifndef GESTION_PASSAGER_H
#define GESTION_PASSAGER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QAbstractItemModel>

class gestion_passager
{
    int CIN,Tel;
    QString nom,prenom,destination,sexe;
    QDate date_naissance;
public:
    //Constructeurs
    gestion_passager(){}
    gestion_passager(int,int,QString,QString,QString,QDate,QString);
    //Getters
    int getCIN(){return CIN;}
    int getTel() {return Tel;}
    QString getnom() {return nom;}
    QString getprenom(){return prenom;}
    QString getdestination() {return destination;}
    QDate getdate_naissance(){return date_naissance;}
    QString getsexe() {return sexe;}

    //Setters
    void setCIN (int CIN){this->CIN=CIN;}
    void setTel (int Tel) {this->Tel=Tel;}
    void setnom (QString n){nom=n;}
    void setprenom(QString p) {prenom=p;}
    void setdestination(QString d) {destination=d;}
    void setdate_naissance (QDate D) {date_naissance=D;}
    void setsexe (QString s){sexe=s;}

    // Fonctionnalite de base relatives a l'entite passager
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier(int,int,QString,QString,QString,QDate);



QSqlQueryModel *rechercher(QString );
  QSqlQueryModel* afficher_P_trie_des();
  QSqlQueryModel* afficher_P_trie_date();

};

#endif // GESTION_PASSAGER_H
