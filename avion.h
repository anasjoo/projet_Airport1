#ifndef AVION_H
#define AVION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

//

class avion
{ QString id ,nom ,salaire,heurepayee,note,heuresup ;

public:
    avion();
    avion(QString,QString,QString,QString,QString,QString);


    QString getid();
    QString getnom();
    QString getsalaire();
    QString getheurepayee();
    QString getnote();
    QString getheuresup();


    void setid(QString);
    void setnom(QString);
    void setsalaire(QString);
    void setheurepayee(QString);
    void setnote(QString);
    void setheuresup(QString);


bool ajouter();
bool modifier();
QSqlQueryModel* afficher();
QSqlQueryModel *trieravion();
QSqlQueryModel* recherche(QString);
bool supprimer (QString);


private:
   // QString id,salaire,heurepayee,note,heuresup;
   // QString nom;

    //F de base relatives à lentité avion
};

#endif // AVION_H
