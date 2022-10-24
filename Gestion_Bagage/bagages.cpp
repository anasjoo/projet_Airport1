#include "bagages.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>



Bagages::Bagages()
{
    idPassager="";
    idBagage="";
    poids=0;
    type="";

}
Bagages::Bagages(QString idPassager,QString idBagage,float poids,QString type)
{
    this->idPassager=idPassager;
    this->idBagage=idBagage;
    this->poids=poids;
    this->type=type;
}
bool Bagages::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into SA_BAGAGES(ID_BAGAGE,POIDS,TYPE, ID_PASSAGER) VALUES (:idBagage , :poids,:type, :idPassager)");
        q.bindValue(":idBagage",ui->id_bagage_2->text());
        q.bindValue(":idPassager",ui->id_passager_2->text());
        q.bindValue(":poids",ui->poids_2->text());
        q.bindValue(":type",ui->type_2->currentText());


        if (    q.exec())
        {
            std::cout << "ca marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("valise ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("valise n est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
    bool Bagages::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update SA_BAGAGES set  ID_BAGAGE=:idBagage, POIDS=:poids,TYPE=:type,ID_PASSAGER=:idPassager where ID_BAGAGE=:idBagage" );
    q.bindValue(":idBagage",ui->UPbagage->text());
    q.bindValue(":idPassager",ui->UPpassager->text());
    q.bindValue(":poids",ui->UPpoids->text());
    q.bindValue(":type",ui->UPtype->currentText());

    if(q.exec())
    {
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("les informations valise  ont ete modifie ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("les informations valise n ont pas modifie ");
                    msgBox.exec();
                    return false;
        }
}
}

bool Bagages::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM SA_BAGAGES WHERE ID_BAGAGE ='"+ui->id_bagageD_2->text()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la valise a ete supprimee ");
                     msgBox.exec();
             return true;
         }
         else

{
             QMessageBox msgBox ;
                     msgBox.setText("la valise n'est pas supprimee' ");
                     msgBox.exec();
             return false;
}
}


void Bagages::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from SA_BAGAGES");
    q.exec();
    modal->setQuery(q);
    ui->viewBagage->setModel(modal);
}

