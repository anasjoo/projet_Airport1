#include "employer.h"
#include "ui_employer.h"
#include<QtDebug>
#include<QMessageBox>
#include <QSqlQuery>
#include <QPainter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QtDebug>
#include <QtCharts>
#include <QChartView>
#include <QLegend>
#include <QPieSeries>
#include <QPieSlice>
#include "arduino.h"


employer::employer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employer)
{
    ui->setupUi(this);


    ui->tab_empl->setModel(E.afficher());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).
}


void employer::update_label()
{
    data=A.read_from_arduino();

    qDebug() << data;

    if(c.length()+data.length()>12)
    {int j=0;
        for(int i=c.length();i<12;i++)
        {
            if(data[j]!='/' || data[j]!='r' || data[j]!='n' )
            c[i]=data[j];
            j++;
        }
        t++;
    }
    else
    {
        c+=data;
    }
    qDebug()<<c;
    QSqlQuery query;

    query=E.request(c);
    bool test = false;
    if(query.exec())
    {
        while(query.next())
        {
            test = true;
        }
    }
   /* if(test)
    {
        QMessageBox::information(this,"Login","Acess granted");
        //hide();
        ui->stackedWidget->setCurrentIndex(0);
         A.write_to_arduino("1");

    }*/
    else {
        if (c.length()==12)
        {
            A.write_to_arduino("2");
        }
    }

    if(c.length()>=12)
    {
        t=0;
        c="";
    }
}

employer::~employer()
{
    delete ui;
}

void employer::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->text();
    Employee E(id,nom,prenom,fonction);

    bool test=E.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""click cancel to exit."),QMessageBox::Cancel);
       ui->tab_empl->setModel((E.afficher()));
        }
        else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);

}



void employer::on_pb_supp_clicked()
{
    Employee E1;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    if (test )
    {QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppresion effectuer. \n"
                            "click to exit"),QMessageBox::Cancel);
        ui->tab_empl->setModel(E.afficher());
    }
    else
        QMessageBox ::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr ("suppresion non effectuer. \n"
                                            "click to exit"),QMessageBox::Cancel);


}

void employer::on_pb_modif_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString fonction=ui->le_fonction_2->text();
    Employee E(id,nom,prenom,fonction);

    bool test=E.modifier();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""click cancel to exit."),QMessageBox::Cancel);
       ui->tab_empl->setModel((E.afficher()));
        }
        else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);

}


void employer::on_rechPB_clicked(){
    QMessageBox msgBox;

            QSqlQuery query;
            int id=0,numtel=0;
            QString nom="",prenom="",email="";


            int critere=ui->comborech->currentIndex();
            if(critere==0)
            {

                id=ui->rech->text().toInt();

                //d=C1.getId();

                //x.chercheremployes(critere);
                query.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES WHERE ID =:id " );
                query.bindValue(":id", id);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    prenom=query.value(2).toString();
                    email=query.value(3).toString();
                    numtel=query.value(4).toInt();

               }
            }
            else if(critere==1)
            {
                nom=ui->rech->text();

                //d=C1.getId();

                //x.chercheremployes(critere);
                query.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES WHERE NOM =:nom " );
                query.bindValue(":nom", nom);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    prenom=query.value(2).toString();
                    email=query.value(3).toString();
                    numtel=query.value(4).toInt();

               }
            }
            else
            {
                prenom=ui->rech->text();

                //d=C1.getId();

                //x.chercheremployes(critere);
                query.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES WHERE PRENOM =:prenom " );
                query.bindValue(":prenom", prenom);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    prenom=query.value(2).toString();
                    email=query.value(3).toString();
                    numtel=query.value(4).toInt();

               }
            }
            if(email=="")
            {


                  QMessageBox::critical(nullptr, QObject::tr("CLIENT not found"),
                           QObject::tr("try again"), QMessageBox::Cancel);


            }
            else
            {

                msgBox.setText("FOUND");
                ui->lidRech->setText(QString::number(id));
                ui->lnomRech->setText(nom);
                ui->lprenomRech->setText(prenom);
                ui->lFonctionRech->setText(email);
                msgBox.exec();
            }
}


void employer::on_tri_id_clicked()
{
    ui->tab_empl->setModel(E.tri());

}

void employer::on_tri_nom_clicked()
{
    ui->tab_empl->setModel(E.tri1());

}

void employer::on_tri_prenom_clicked()
{
    ui->tab_empl->setModel(E.tri2());

}
//pdf
void employer::on_tab_empl_clicked(const QModelIndex &index)
{
    QString id=ui->tab_empl->model()->data(index).toString();
     QSqlQuery qry;
     qry.prepare("select id,nom,prenom,fonction from EMPLOYES where id=:id");
     qry.bindValue(":id",id);
     if (qry.exec())
     {
         while(qry.next())
         {


             QString s=("ID: "+qry.value(0).toString()+"\n""Nom: "+qry.value(1).toString()+"\n""Prenom: "+qry.value(2).toString()+"\n""Fonction: "+qry.value(3).toString());
             ui->pdf->setText(s);
         }
     }
         else
         {
            QMessageBox::warning(this,"error","no information");
         }
}
void employer::on_convertir_clicked()
{
    QPrinter printer ;
        printer.setPrinterName("fichier");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)
        {

            return ;
        }
        else
            ui->pdf->print(&printer);
}


//login
/*void employer::on_loginPB_clicked()
{

    {
        QString username=ui->idLogin->text();
            QString password=ui->pwdLogin->text();

            if(username=="aziz" && password=="2206")
            {


                QMessageBox::information(this,"Login","Username and Password are correct");

                 ui->stackedWidget->setCurrentIndex(0);


            }

            else


                QMessageBox::warning(this,"Login","Username and Password are not correct");
    }

}*/
//stat
void employer::on_pb_stat_clicked()
{
    QSqlQuery q1,q2,q3,q4;
            qreal tot=0,c1=0,c2=0;

            q1.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES");

            if(q1.exec())
            {
              while (q1.next())
              {
                  tot++;
              }
            }

            q2.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES WHERE FONCTION='admin'");
            if(q2.exec())
            {
              while (q2.next())
              {
                  c1++;
              }

            }

            q3.prepare("SELECT id,nom,prenom,fonction FROM EMPLOYES WHERE FONCTION='employee'");
            if(q3.exec())
            {
              while (q3.next())
              {
                  c2++;
              }
            }



            c1=c1/tot;
            c2=c2/tot;


                QPieSeries *series = new QPieSeries();
                series->append("admin ",c1);
                series->append("employee",c2);
                QPieSlice *slice0 = series->slices().at(0);
                            slice0->setExploded();
                            slice0->setLabelVisible();
                            slice0->setPen(QPen(Qt::darkGray, 2));
                            slice0->setBrush(Qt::gray);
                QPieSlice *slice1 = series->slices().at(1);
                            slice1->setExploded();
                            slice1->setLabelVisible();
                            slice1->setPen(QPen(Qt::darkRed, 2));
                            slice1->setBrush(Qt::red);

                            QChart *chart = new QChart();
                                        chart->addSeries(series);
                                        chart->setTitle("Stat");
                                        chart->setAnimationOptions(QChart::AllAnimations);
                                        chart->legend()->hide();
                                        QChartView *chartView = new QChartView(chart);
                                                    chartView->setRenderHint(QPainter::Antialiasing);
                                                    QGridLayout *layout = new QGridLayout();
                                                    layout->addWidget(chartView);
                                                    ui->label_stat->setLayout(layout);
}


void employer::on_retourner_clicked()
{
    hide();
}
