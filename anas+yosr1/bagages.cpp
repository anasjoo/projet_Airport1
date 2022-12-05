#include "bagages.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>
#include "smtp.h"


bool valid_id(QString id)
{
    for (int i=0 ; i<id.length() ;  i++)
    {
        if (id[i] >= 'a' || id[i] <= 'z')
        {

        }
        else
            return false ;
    }
    return true ;
}

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
float Bagages::poidstotal(Ui::MainWindow *ui)
{
    QSqlQuery q;
    float poidsTotal =0;

        q.prepare("select * from BAGAGES where ID_PASSAGER =:id");
        q.bindValue(":id",ui->id_passager_2->currentText());
        q.exec();
       while ( q.next())

        poidsTotal+= q.value(2).toReal();
        std :: cout << poidsTotal <<std :: endl ;




             return poidsTotal;

}

bool Bagages::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into BAGAGES(ID_BAGAGE,POIDS,TYPE, ID_PASSAGER) VALUES (:idBagage , :poids,:type, :idPassager)");
        //q.bindValue(":idBagage",if (qtextlength(ui->id_bagage_2->text()<4);
         q.bindValue(":idBagage",ui->id_bagage_2->text());
        q.bindValue(":idPassager",ui->id_passager_2->currentText());
        q.bindValue(":poids",ui->poids_2->text());
        q.bindValue(":type",ui->type_2->currentText());

    if (ui->id_bagage_2->text().size() == 4 && valid_id((ui->id_bagage_2->text())))
{ float sumBa;
      sumBa =ui->poids_2->text().toFloat() +poidstotal(ui);

      std :: cout <<"somme"<<sumBa<<std :: endl;
    if  ( sumBa <= 23)
        {
            if (q.exec())
            {
                std::cout << "ca marche ! 🙂" << std::endl;

                QMessageBox msgBox ;
                        msgBox.setText("valise ajoute ");
                        msgBox.exec();

                        Smtp* smtp = new Smtp("anas.joo@esprit.tn",mail_pass, "smtp.gmail.com");

                                  smtp->sendMail("anas.joo@esprit.tn","anas.joo@esprit.tn" ," cabine num : 1 'i' ","bagage enregistré");
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
        else
        {
            QMessageBox msgBox ;
                    msgBox.setText("il faut payer pour un bagage supplémetaire");
                    msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox ;
                msgBox.setText("invalid id ");
                msgBox.exec();
    }


    /*    if (ui->id_bagage_2->text().size() == 4 && valid_id((ui->id_bagage_2->text())))
        { if (ui->poids->text().toFloat() < 40)
            {
                if (q.exec())
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
            else
            {
                QMessageBox msgBox ;
                        msgBox.setText("poids ghalet");
                        msgBox.exec();
            }
        }
        else
        {
            QMessageBox msgBox ;
                    msgBox.setText("invalid id ");
                    msgBox.exec();
        }
*/

}
bool Bagages::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update BAGAGES set  ID_BAGAGE=:idBagage, POIDS=:poids,TYPE=:type,ID_PASSAGER=:idPassager where ID_BAGAGE=:idBagage" );
    q.bindValue(":idBagage",ui->UPbagage->text());
    q.bindValue(":idPassager",ui->UPpassager->currentText());
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

         q.prepare("DELETE FROM BAGAGES WHERE ID_BAGAGE ='"+ui->id_bagageD_2->text()+"'");


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
    q.prepare("select * from BAGAGES");
    q.exec();
    modal->setQuery(q);
    //ui->viewBagage->setModel(modal);
    ui->viewBagage->setModel(modal);
    QSqlQuery qc;
    QSqlQueryModel *model=new QSqlQueryModel();
    qc.prepare("select ID_PASSAGER from PASSAGERS");
    qc.exec();
    model->setQuery(qc);
    //ui->viewBagage->setModel(modal);
    ui->id_passager_2->setModel(model);
    ui->UPpassager->setModel(model);

}


  QSqlQueryModel *Bagages::trierBagages()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select * from BAGAGES order by POIDS");
    // ui->triBagage->setModel(model);
   return model ;

}
QSqlQueryModel *Bagages::rechercherBagages(QString id_Bagage)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from BAGAGES where ID_BAGAGE= '"+id_Bagage+"' ");
        //query.prepare("select * from BAGAGES where ID_BAGAGE ORDER BY ID_BAGAGE");
        query.exec();
        model->setQuery(query);
        return model;

}

/*void GPS::search(const QString & Address )
{
    QUrl url = QString( "http://maps.google.fr/maps?f=q&hl=fr&q=%1" )
       .arg( Address );


    if ( !QDesktopServices::openUrl( url ) )
    {
        // echec
    }
}*/
