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
    QString mail_pass="QoranKarim123*";




public:
    //Constructeurs
    Bagages();
    Bagages(QString, QString,float,QString);


    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    float poidstotal(Ui::MainWindow *ui);
    QSqlQueryModel *trierBagages();
    QSqlQueryModel *rechercherBagages(QString idBagage);



};


#endif // BAGAGES_H
