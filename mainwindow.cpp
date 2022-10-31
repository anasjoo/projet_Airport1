#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bagages.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Ajouter_clicked()
{
     Bagages b;
      b.ajouter(ui);
      b.AfficherTable(ui);

    /* bool test =b.ajouter(ui);
     if (test){

      b.AfficherTable(ui);
     }*/
}

void MainWindow::on_Modifier_clicked()
{
     Bagages b;
      b.Modifier(ui);
      b.AfficherTable(ui);

    /* bool test =b.Modifier(ui);
     if (test){
          b.AfficherTable(ui);


     }*/

}
void MainWindow::on_Supprimer_clicked()
{
     Bagages b;
     b.supprimer(ui);
     b.AfficherTable(ui);

    /* bool test =b.supprimer(ui);
     if (test){
           b.AfficherTable(ui);


     }*/

}

/*void MainWindow::on_consulter_clicked()
{
    Bagages b;
    b.AfficherTable(ui);
}*/

void MainWindow::on_Bagage_currentChanged(int index)
{
    Bagages b;

    b.AfficherTable(ui);
}


void MainWindow::on_TriBouton_clicked()
{
    Bagages *b= new Bagages();
    ui->triBagage->setModel(b->trierBagages());

}


void MainWindow::on_recherche_clicked()
{
    QString valeur=ui->id_bagageRecherche->text();
    Bagages *b=new Bagages();
    ui->viewBagageRecherche->setModel(b->rechercherBagages(valeur));
    b->AfficherTable(ui);
}



