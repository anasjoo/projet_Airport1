#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditid_vol->setValidator(new QIntValidator(0,9999999,this));
    ui->tablevol->setModel(V.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButtonajouter_clicked()
{
    bool test;
    int ID_VOL=ui->lineEditid_vol->text().toInt();
    QString DIRECTION=ui->lineEditdirection->text();
    QString ARRIVE_VOL=ui->lineEditarrive_vol->text();
    QString DEPART_VOL=ui->lineEditdepart_vol->text();
    Vol V(ID_VOL,DIRECTION,ARRIVE_VOL,DEPART_VOL);
    QMessageBox msg ;
    test=V.ajouter();
    if (test)
    { msg.setText("ajout par succes");
        ui->tablevol->setModel(V.afficher());
    }

    else
        msg.setText("echec d'ajout");
        msg.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

    V.setID_VOL(ui->lineEditid_vol->text().toInt());
    bool test=V.supprimer(V.getID_VOL());
    QMessageBox msg;
    if (test)
    {
        msg.setText("suppression avec succes!");
        ui->tablevol->setModel(V.afficher());

    }
    else
        msg.setText(("!!echec de suppression"));
        msg.exec();
}

void MainWindow::on_modifier_2_clicked()
{
   int id;
  int ID_VOL = ui->lineEditid_2->text().toInt();
  QString DIRECTION= ui->lineEditdirection_2->text();
  QString DEPART_VOL= ui->lineEditdepart->text();
  QString ARRIVE_VOL= ui->lineEditarrive->text();
  Vol V (ID_VOL,DIRECTION,DEPART_VOL,ARRIVE_VOL);
  if(ID_VOL!=0 && DIRECTION!="" && DEPART_VOL!="" && ARRIVE_VOL!="")
  {
      bool test=V.modifier(id);
      QMessageBox msgBox;
      if (test)
{         msgBox.setText("succes de modification");
      /*    ui->lineEditid_2->clear();
          ui->lineEditdirection_2->clear();
          ui->lineEditdepart->clear();
          ui->lineEditarrive->clear();*/
          ui->tablevol->setModel(V.afficher());
}
      else
          msgBox.setText("echec de modification");
      msgBox.exec();
  }
}
