#ifndef BAGAGES_H
#define BAGAGES_H
#include <Qstring>
#include <iostream>
#include "ui_MainWindow.h"
#include "MainWindow.h"
#include <QtSql/QSqlQueryModel>


class Bagages
{
private:
    QString idBagage;
    QString idPassager;
    float poids;
    QString type;




public:
    //Constructeurs
    Bagages();
    Bagages(QString, QString,float,QString);


    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    QSqlQueryModel *trierBagages();
    QSqlQueryModel *rechercherBagages(QString idBagage);


};


#endif // BAGAGES_H
