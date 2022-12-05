#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avion.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTableView>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QPieSlice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ avion a;
    ui->setupUi(this);
    ui->tabavion->setModel(a.afficher());
    ui->tabavion->setModel(a.afficher());//appel du methode afficher from attribut
}

MainWindow::~MainWindow()
{
delete ui;
}


void MainWindow::on_pbajouter_clicked()
{//recuperation des informations saisises

    QString id=ui->id->text();
    QString nom=ui->nom->text();
    QString salaire=ui->salaire->text();
    QString heurepayee=ui->heurepayee->text();
    QString note=ui->note->text();
    QString heuresup=ui->heuresup->text();

     //object du classe avion

    avion a (id,nom,salaire,heurepayee,note,heuresup);

    //test du requete

    bool test=a.ajouter();

    if (test)
    {
        ui->tabavion->setModel(a.afficher());
        ui->tabavion->setModel(a.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("Ajout effectué "),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                           QObject::tr("Ajout non effectué."),
                              QMessageBox::Cancel);

}



void MainWindow::on_pbajouter_2_clicked()
{

       QString id=ui->id_3->text() ;
       QString nom=ui->nom_2->text() ;
       QString salaire=ui->salaire_2->text() ;
       QString heurepayee=ui->heurepayee_3->text();
       QString note=ui->note_2->text();
       QString heuresup=ui->heuresup_2->text() ;

avion a( id, nom, salaire, heurepayee, note, heuresup);
     bool test=a.modifier() ;

       QMessageBox msgBox;

       if(test)
          {
           msgBox.setText("Modification avec succes.");
           ui->tabavion->setModel(a.afficher());
          ui->tabavion->setModel(a.afficher()) ;
          }
       else
           msgBox.setText("Echec de Modification.!!!");
           msgBox.exec();
}



QSqlQueryModel * avion::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
          model->setQuery("SELECT* FROM AVION");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREPAYEE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOTE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEURESUP"));
          return model ;
}

void MainWindow::on_pbajouter_3_clicked()  //afficher
{
    QString id=ui->id_3->text() ;
    QString nom=ui->nom_2->text() ;
    QString salaire=ui->salaire_2->text() ;
    QString heurepayee=ui->heurepayee_3->text();
    QString note=ui->note_2->text();
    QString heuresup=ui->heuresup_2->text() ;

avion a( id, nom, salaire, heurepayee, note, heuresup);
  bool test=a.modifier() ;

    QMessageBox msgBox;

    if(test)
       {
        msgBox.setText("affichage avec succes.");
        ui->tabavion->setModel(a.afficher());
       }
    else
        msgBox.setText("Echec d'affichage .!!!");
        msgBox.exec();
}

void MainWindow::on_pbajouter_10_clicked() //trier
{

    QString id=ui->id_3->text() ;
    QString nom=ui->nom_2->text() ;
    QString salaire=ui->salaire_2->text() ;
    QString heurepayee=ui->heurepayee_3->text();
    QString note=ui->note_2->text();
    QString heuresup=ui->heuresup_2->text() ;

avion a( id, nom, salaire, heurepayee, note, heuresup);
    ui->trier_2->setModel(a.afficher());

}



void MainWindow::on_pbajouter_12_clicked()
{
    using namespace QtCharts;
        QSqlQueryModel * model= new QSqlQueryModel();
                                 model->setQuery("select * from AVION where HEUREPAYEE <15 ");
                                 float a=model->rowCount();
                                 model->setQuery("select * from AVION where HEUERPAYEE between 15 and 30 ");
                                 float aa=model->rowCount();
                                 model->setQuery("select * from AVION where HEUREPAYEE >30 ");
                                 float aaa=model->rowCount();
                                 float total=a+aa+aaa;
                                 QString d=QString("HEUREPAYEE INFERIEUR A 15 "+QString::number((a*100)/total,'f',2)+"%" );
                                 QString b=QString("HEUREPAYEE ENTRE 15 ET 30 "+QString::number((aa*100)/total,'f',2)+"%" );
                                 QString c=QString("HEUREPAYEE SUPERIEUR A 30 "+QString::number((aaa*100)/total,'f',2)+"%" );
                                 QPieSeries *series = new QPieSeries();
                                 series->append(d,a);
                                 series->append(b,aa);
                                 series->append(c,aaa);
                         if (a!=0)
                         {QPieSlice *slice = series->slices().at(0);
                          slice->setLabelVisible();
                          slice->setPen(QPen());}
                         if (aa!=0)
                         {
                                  // Add label, explode and define brush for 2nd slice
                                  QPieSlice *slice1 = series->slices().at(1);
                                  //slice1->setExploded();
                                  slice1->setLabelVisible();
                         }
                         if(aaa!=0)
                         {
                                  // Add labels to rest of slices
                                  QPieSlice *slice2 = series->slices().at(2);
                                  //slice1->setExploded();
                                  slice2->setLabelVisible();
                         }
                                 // Create the chart widget
                                 QChart *chart = new QChart();
                                 // Add data to chart with title and hide legend
                                 chart->addSeries(series);
                                 chart->setTitle("Statistiques de la capacité des salles  "+ QString::number(total));
                                 chart->legend()->hide();
                                 // Used to display the chart
                                 QChartView *chartView = new QChartView(chart);
                                 chartView->setRenderHint(QPainter::Antialiasing);
                                 chartView->resize(1000,500);
                                 chartView->show();

}
void MainWindow::on_LE_Chercher_textChanged(const QString &arg1)
{


    ui->LE_Chercher->setValidator( new QIntValidator(0, 999999, this));
    if(ui->LE_Chercher->text()!="")
    {
      QString id=ui->LE_Chercher->text();
      ui->tabavion->setModel(a.recherche(id));
    }
    else
     ui->tabavion->setModel(a.afficher());
}
void MainWindow::on_pushButton_Supp_clicked()
{

    a.setid(ui->LE_supp->text());
    bool test=a.supprimer(a.getid());


    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                    QObject::tr("Suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tabavion->setModel(a.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                    QObject::tr("OUPS, Suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

