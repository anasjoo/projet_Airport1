#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "passager.h"
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



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LE_Tel->setValidator( new QIntValidator(00000001, 99999999, this));
ui->tab_passager->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_Ajouter_clicked()
{

 int CIN=ui->LE_CIN->text().toInt();
   int Tel=ui->LE_Tel->text().toInt();
    QString nom=ui->LE_Nom->text();
    QString prenom=ui->LE_Prenom->text();
    QString destination=ui->LE_Dest->text();
    QDate date_naissance=ui->dateEdit->date();
    QString sexe=ui->comboBox_sexe->currentText();
   Passager P(CIN, Tel,nom,prenom,destination,date_naissance,sexe);
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




void MainWindow::on_pushButton_Supp_clicked()
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

void MainWindow::on_pushButton_Modifier_clicked()
{

        int CIN=ui->LE_CIN->text().toInt();
         int Tel=ui->LE_Tel->text().toInt();
        QString nom=ui->LE_Nom->text();
        QString prenom=ui->LE_Prenom->text();
        QString destination=ui->LE_Dest->text();
       QDate date_naissance=ui->dateEdit->date();
       QString sexe=ui->comboBox_sexe->currentText();

      Passager P(CIN, Tel,nom,prenom,destination,date_naissance,sexe);

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


void MainWindow::on_LE_Chercher_textChanged(const QString &arg1)
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


void MainWindow::on_comboBox_Tri_currentIndexChanged(const QString &arg1)
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

void MainWindow::on_pushButton_PDF_clicked()
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
    painter.drawText(5700,3300,"Destination");
    painter.drawText(7300,3300,"Date naissance");
     painter.drawText(9000,3300,"Prénom");

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
        painter.drawText(5900,i,query.value(3).toString());
        painter.drawText(7300,i,query.value(4).toString());
        painter.drawText(9000,i,query.value(5).toString());

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







void MainWindow::on_stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}






void MainWindow::on_pushButton_envoyer_clicked()
{
    Smtp* smtp = new Smtp("yosr.kheriji@esprit.tn", "211JMT9456", "smtp.gmail.com", 465);


        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        QString a=ui->LE_Destinataire->text();


        QString b=ui->LE_Objet->text();


        QString c=ui->lineEdit_msg->text();




        smtp->sendMail("yosr.kheriji@esprit.tn", a , b,c);
}

void MainWindow::on_pushButton_imprimer_clicked()
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

