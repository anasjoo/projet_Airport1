#include "passager.h"
#include "ui_passager.h"
#include "qmessagebox.h"
#include "connection.h"
#include "gestion_passager.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include "stat.h"

#include <QPrintDialog>
#include <QFileDialog>


Passager::Passager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passager)
{
    ui->setupUi(this);
    ui->LE_Tel->setValidator( new QIntValidator (00000001, 99999999, this));
ui->tab_passager->setModel(P.afficher());

QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                   QCoreApplication::organizationName(), QCoreApplication::applicationName());


  ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/A%C3%A9roport+de+Tunis-Carthage/@36.8475605,10.2149852,17z/data=!3m1!4b1!4m5!3m4!1s0x12e2cad2e1d7f1bb:0x902488d100b5819b!8m2!3d36.8475562!4d10.2175601");
//Arduino

  int ret =A.connect_arduino();//lancer la connection to arduino
      switch (ret) {

      case(0):qDebug()<<"arduino is available and connect to : "<<A.getarduino_port_name();
          break;
      case(1):qDebug()<<"arduino is available and not  connect to : "<<A.getarduino_port_name();
          break;
      case(-1):qDebug()<<"arduino is not available ";
          break;

      }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}

Passager::~Passager()
{
    delete ui;
}

void Passager::on_pushButton_Ajouter_clicked()
{

 int CIN=ui->LE_CIN->text().toInt();
   int Tel=ui->LE_Tel->text().toInt();
    QString nom=ui->LE_Nom->text();
    QString prenom=ui->LE_Prenom->text();
    QString destination=ui->LE_Dest->text();
    QDate date_naissance=ui->dateEdit->date();
    QString sexe=ui->comboBox_sexe->currentText();
   gestion_passager P(CIN, Tel,nom,prenom,destination,date_naissance,sexe);
bool test=P.ajouter();
if(test)
{

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Ajout effectue\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tab_passager->setModel(P.afficher());

}
else
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("Ajout non effectue.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}




void Passager::on_pushButton_Supp_clicked()
{

    P.setCIN(ui->LE_supp->text().toInt());
    bool test=P.supprimer(P.getCIN());


    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                    QObject::tr("Suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_passager->setModel(P.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                    QObject::tr("OUPS, Suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Passager::on_pushButton_Modifier_clicked()
{

        int CIN=ui->LE_CIN->text().toInt();
         int Tel=ui->LE_Tel->text().toInt();
        QString nom=ui->LE_Nom->text();
        QString prenom=ui->LE_Prenom->text();
        QString destination=ui->LE_Dest->text();
       QDate date_naissance=ui->dateEdit->date();
       QString sexe=ui->comboBox_sexe->currentText();

      gestion_passager P(CIN, Tel,nom,prenom,destination,date_naissance,sexe);

     bool test=P.modifier(CIN, Tel,nom,prenom,destination,date_naissance);
        if(test)
        {
            ui->tab_passager->setModel(P.afficher());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                        QObject::tr("La modification est effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modification"),
                        QObject::tr("OUPS, La modification n'a pas été effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}


void Passager::on_LE_Chercher_textChanged(const QString &arg1)
{

    ui->LE_Chercher->setValidator( new QIntValidator(0, 999999, this));
    if(ui->LE_Chercher->text()!="")
    {
      QString CIN=ui->LE_Chercher->text();
      ui->tab_passager->setModel(P.rechercher(CIN));
    }
    else
     ui->tab_passager->setModel(P.afficher());
}


void  Passager::on_comboBox_Tri_currentIndexChanged(const QString &arg1)
{
    QString crit=ui->comboBox_Tri->currentText();
    if(crit=="destination")
    {
      ui->tab_passager->setModel(P.afficher_P_trie_des());
    }
    else if (crit=="date naissance")
    {
      ui->tab_passager->setModel(P.afficher_P_trie_date());
    }

}
QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}

void Passager::on_pushButton_PDF_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/HP/Desktop/Gestion_Passagers/passager.pdf");

    QPainter painter(&printer);
    painter.drawPixmap(QRect(100,200,2500,2500),QPixmap("C:/Users/HP/Desktop/Gestion_Passagers/logo.png")); //logo
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 40));
    painter.drawText(3050,1400,"Liste des Passagers");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawRect(2700,200,6500,2000);
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial",10));
    painter.drawText(300,3300,"CIN");
    painter.drawText(2000,3300,"Nom");
    painter.drawText(3800,3300,"Tel");
    painter.drawText(5000,3300,"Destination");
    painter.drawText(6500,3300,"Date naissance");
     painter.drawText(8800,3300,"Prénom");

    QString date= currDate() ;
    painter.drawText(8500,30,date);

    QSqlQuery query;
    query.prepare("select * from PASSAGERS  ");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1900,i,query.value(1).toString());
        painter.drawText(3500,i,query.value(2).toString());
        painter.drawText(5300,i,query.value(3).toString());
        painter.drawText(6500,i,query.value(4).toString());
        painter.drawText(8800,i,query.value(5).toString());

        i = i + 500;
    }

    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/Gestion_Passagers/passager.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}







void Passager::on_stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}






void Passager::on_pushButton_envoyer_clicked()
{
    Smtp* smtp = new Smtp("yosr.kheriji@esprit.tn", "211JMT9456", "smtp.gmail.com", 465);


        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        QString a=ui->LE_Destinataire->text();


        QString b=ui->LE_Objet->text();


        QString c=ui->lineEdit_msg->text();




        smtp->sendMail("yosr.kheriji@esprit.tn", a , b,c);
}

void Passager::on_pushButton_imprimer_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,"Open File",QString(),"PDF File(*.pdf)");


    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer,0);


    if(dlg->exec() == QDialog::Accepted)

    {

        QImage pdf(fileName);

        QPainter painter(&printer);

        painter.drawImage(QPoint(0,0),pdf);

        painter.end();

    }


    delete dlg;

}

void Passager::update_label()
{
    Connection c;

    data=A.read_from_arduino();

    ui->label_arduino->setText(data);

    QSqlQuery query(test_bd);
    QString select = "SELECT ID_PASSAGER from PASSAGERS where ID_PASSAGER=?";
    qDebug() << select;
    query.prepare(select);
    query.addBindValue(ui->label_arduino->text());
    query.exec();
   if (query.exec())
    {

        int count=0;
        while (query.next())
        {
            count++;
        }
        if (count==1)
        {

            A.write_to_arduino("1");
            ui->label_arduino->setText("Welcome ");

        }

         else if (count<1)
        {
            A.write_to_arduino("0");

        }
    }
   if (data=="2"){
         ui->label_arduino->setText("No More Places");

   }
    //afficher on si les données reçues par arduino est 1

}



void Passager::on_retourner_clicked()
{
    hide();
}
