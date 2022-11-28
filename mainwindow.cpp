#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "billet.h"
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include<QFile>
#include<QFileDialog>
#include <QMessageBox>
#include <QPdfWriter>
#include <QTextStream>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QDate>
#include "smtp.h"
#include <fstream>
#include <QSslSocket>
#include <QIntValidator>
#include <QAbstractSocket>
#include "qrcode.h"
#include <QPixmap>
#include<QRegularExpression>
#include "excel.h"
using qrcodegen::QrCode ;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999999,this));
    ui->le_NUMV->setValidator(new QIntValidator(0,999999,this));
    ui->le_NUMS->setValidator(new QIntValidator(0,9999,this));
    ui->tabE->setModel(Etmp.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
       connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
       //arduino
                     int ret=A1.connect_arduino();
                          switch(ret)
                          {
                          case(0):qDebug()<<"arduino is available and connected to:"<<A1.getarduino_port_name();
                                 break;
                          case(1):qDebug()<<"arduino is available but not connected to:"<<A1.getarduino_port_name();
                              break;
                          case(-1):qDebug()<<"arduino is not available";
                              break;
                          }
QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer le slot update_label suite à la reception du signal readyRead (reception des données).

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_ajouter_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    int NUMV=ui->le_NUMV->text().toInt();
    int NUMS=ui->le_NUMS->text().toInt();

       Billet s(id,NUMV,NUMS);
      bool test=s.ajouter();
       if(test){
           //refresh
           ui->tabE->setModel(Etmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue\n""click cancel to exit"),QMessageBox::Cancel);
       }else{
           QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n""click cancel to exit"),QMessageBox::Cancel);
       }
}


void MainWindow::on_pbSupprimer_clicked()
{
    int sup=ui->le_IDsup->text().toInt();
    bool test=Etmp.supprimer(sup);
    if(test){
         ui->tabE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectues\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }


}


void MainWindow::on_updateBP_clicked()
{
    int up=ui->up_ID->text().toInt();
    int NUMV=ui->up_NUMV->text().toInt();
    int NUMS=ui->up_NUMS->text().toInt();

    Billet s(up,NUMV,NUMS);
    bool test=s.update(up);
    if(test){
         ui->tabE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("update effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("update non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString strStream;

            strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");

                if (QFileInfo(strStream).suffix().isEmpty())

                    { strStream.append(".pdf"); }



                QPrinter printer(QPrinter::PrinterResolution);

                printer.setOutputFormat(QPrinter::PdfFormat);

                printer.setPaperSize(QPrinter::A4);

                printer.setOutputFileName(strStream);



                      QTextStream out(&strStream);



                      const int rowCount = ui->tabE->model()->rowCount();

                      const int columnCount = ui->tabE->model()->columnCount();

                      QString TT = QDateTime::currentDateTime().toString();

                      out <<"<html>\n"

                            "<head>\n"

                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                          << "<title>ERP - COMmANDE LIST<title>\n "

                          << "</head>\n"

                          "<body bgcolor=#ffffff link=#5000A0>\n"

                             "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"

                            +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />" //path

                          "<h1 style=\"text-align: center;\"><strong> *****LISTE DES BILLETS ***** </strong></h1>"



                          "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "

                            "</br> </br>";

                      // headers

                      out << "<thead><tr bgcolor=#d6e5ff>";

                      for (int column = 0; column < columnCount; column++)

                          if (!ui->tabE->isColumnHidden(column))

                              out << QString("<th>%1</th>").arg(ui->tabE->model()->headerData(column, Qt::Horizontal).toString());

                      out << "</tr></thead>\n";



                      // data table

                      for (int row = 0; row < rowCount; row++) {

                          out << "<tr>";

                          for (int column = 0; column < columnCount; column++)

                        {

                              if (!ui->tabE->isColumnHidden(column)) {

                                  QString data =ui->tabE->model()->data(ui->tabE->model()->index(row, column)).toString().simplified();

                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis

                              }

                          }

                          out << "</tr>\n";

                      }

                      out <<  "</table>\n"

                          "</body>\n"

                          "</html>\n";



                      QTextDocument document;

                      document.setHtml(strStream);

                      document.print(&printer);



}

void MainWindow::on_recher_clicked()
{Billet B ;
    int id=(ui->line->text().toInt());

           ui->tabE->setModel(B.rechercheC(id)) ;
}
/*
void MainWindow::on_trier_clicked()
{


    Billet bill ;
        QString nom=ui->comboBox->currentText();
            if (ui->cro->isChecked())
            {
            ui->tabE->setModel(bill.trier(nom));
            }
            else if (ui->decro->isChecked())
            {
            ui->tabE->setModel(bill.trier2(nom));
            }

} */
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("ayoub.hanfi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("ayoub.hanfi@esprit.tn", ui->rcpt->text() , ui->subject->text() ,ui->msg->text(), files );
    else
        smtp->sendMail("ayoub.hanfi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->text());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void MainWindow::on_pb_code_clicked()
{ Billet C ;
    if(ui->tabE->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                            QObject::tr("Veuillez Choisir un billet du Tableau.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
               else
               {




                           C.setId(ui->lineEdit_ID->text().toInt());
                           C.setNUMS(ui->le_NUMS->text().toInt());
                           C.setNUMV(ui->le_NUMV ->text().toInt());



                 QString  rawQr = "ID_PASSAGER:%1 Num_VOL:%2 Num_Siege:%3 " ;
                    rawQr = rawQr.arg(  C.getId()).arg(  C.getNUMS()).arg(  C.getNUMV());
                    QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);


                  //  const QrCode qr = QrCode::encodeText(std::to_string(idAnim).c_str(), QrCode::Ecc::LOW);
                    std::ofstream myfile;
                    myfile.open ("qrcode.svg") ;
                    myfile << qr.toSvgString(1);
                    myfile.close();
                    QSvgRenderer svgRenderer(QString("qrcode.svg"));
                    QPixmap pix( QSize(140, 140) );
                    QPainter pixPainter( &pix );
                    svgRenderer.render( &pixPainter );
                    ui->label_qrcode->setPixmap(pix);
               }
}

void MainWindow::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               ExportExcelObject obj(fileName, "mydata", ui->tabE);

               //colums to export
               obj.addField(0, "Id", "char(20)");
               obj.addField(2, "numS", "char(20)");
               obj.addField(1, "numV", "char(20)");

               int retVal = obj.export2Excel();
               if( retVal > 0)
               {
                   QMessageBox::information(this, tr("Done"),
                                            QString(tr("%1 records exported!")).arg(retVal)
                                            );
               }

}
void MainWindow::update_label()
{

    data=A1.read_from_arduino();
QSqlQuery query;
QString idP ;
    if(data=="1")
{
        ui->label_ard->setText("OUVERT"); // si les données reçues de arduino via la liaison série sont égales à 1
          QMessageBox::information(this, tr("Card is valid!"), "ACCESS GIVEN , welcome");

}
    else if (data=="0")

       {
        ui->label_ard->setText("FERMER");
     //alors afficher fermer
}
}

