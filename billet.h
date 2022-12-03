#ifndef Billet_H
#define Billet_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QAbstractSocket>
class Billet
{
public:

    Billet(); //constructeurs par defaut
    Billet(int,int,int); // paramétré
    //getters
    int getId();
    int getNUMV();
    int getNUMS();
    //setters
    void setId(int);
    void setNUMV(int);
     void setNUMS(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update(int);
    QSqlQueryModel* rechercheC(int id_string) ;

         void CREATION_PDF();
         QSqlQueryModel* trier(QString nom);
         QSqlQueryModel* trier2(QString nom);
private:
    int id,NUMV;
   int NUMS;
};

#endif // Billet_H
