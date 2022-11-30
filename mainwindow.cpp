#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bagages.h"
#include <QTextLength>
#include <QPainter>
#include <QDesktopServices>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include<QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include "pdf.h"
#include <qcustomplot.h>
#include <QSqlQuery>
#include <QDialog>
#include "smtp.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>
#include "camera.h"
#include <QSound>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     //ui->viewBagage->SetModel(b.AfficherTable(ui));

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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    qDebug()<< data ;
     // double tmpF = data.toFloat();

    // ui->poids_2->setText(QString::number(tmpF));
    ui->poids_2->setText(ui->poids_2->text()+data);

}



void MainWindow::on_Ajouter_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
     Bagages b;
      b.ajouter(ui);
      b.AfficherTable(ui);

    // if  (qtextlength(ui->id_bagage_2->text())<4)
   //  {

   //  }
    /*  b.AfficherTable(ui);
    bool test =b.ajouter(ui);
     if (test){

      b.AfficherTable(ui);
     }*/

    /*  Smtp* smtp = new Smtp("anas.joo@esprit.tn",mail_pass, "smtp.gmail.com");

          smtp->sendMail("anas.joo@esprit.tn","anas.joo@esprit.tn" ," bagagek 7adher","talka bagagek and erajel");*/

}

void MainWindow::on_Modifier_clicked()
{QSound s("C:/Users/chino/Downloads/click.wav");
    s.play();
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
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
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
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();

    Bagages *b= new Bagages();
    ui->triBagage->setModel(b->trierBagages());

}


void MainWindow::on_recherche_clicked()
{

    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();

    QString valeur=ui->id_bagageRecherche->text();
    Bagages *b=new Bagages();
    ui->viewBagageRecherche->setModel(b->rechercherBagages(valeur));
    b->AfficherTable(ui);
}
  /* void MainWindow::on_pdf()
   {
      pdf p;
      p.setModal(true);
      p.exec();

   }

/*void MainWindow::on_pdf()
{ QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/chino/Desktop/PDF/bagage.pdf");
    QPainter painter;
    QImage imagen("C:/Users/chino/Desktop/PDF/bagage.pdf");
    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
       // return 1;
    }


    QString id_passager=ui->id_bagage_2->text();
    QString id_bagaget=ui->id_bagage_2->text();
    QString poids=ui->poids_2->text();
    QString type=ui->type_2->currentText();






    painter.drawImage(40,40,imagen);
    painter.drawText(180, 280, id_bagaget);

    painter.drawText(180, 300, poids);
    painter.drawText(180, 360, type);



    painter.end();
    QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
    QFile file (file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"WARNING","File not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    QPrinter printer1 (QPrinter::ScreenResolution);
        printer1.setDocName("ArithmoTarot - Scores");
        printer1.setPaperSize(QPrinter::A4);
        printer1.setOrientation(QPrinter::Portrait);

        QPrintDialog printDialog(&printer1, this);
        printDialog.setOption(QAbstractPrintDialog::PrintToFile);

        if (printDialog.exec() == QDialog::Accepted)
        {
            QPainter painter1;
            painter1.begin(&printer);
            painter1.setPen(Qt::black);
            painter1.setFont(QFont("Arial", 12));
            painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
            painter1.drawText(QPointF(100,100), text);
            painter1.end();
        }

}*/



/*void MainWindow::on_pushButton_clicked()
{
    pdf p;
    p.setModal(true);
    p.exec();
  qDebug() << "anas";
}*/




void MainWindow::on_pdfbouton_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
    pdf p;
    p.setModal(true);
    p.exec();
}
QVector<double> MainWindow::Statistique_type()
{
    QSqlQuery q;
    QVector<double> stat(2);
    stat[0]=0;
    stat[1]=0;

    q.prepare("SELECT TYPE FROM BAGAGES WHERE TYPE='leger'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT TYPE FROM BAGAGES WHERE TYPE='lourd'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

    return stat;
}
void MainWindow::makePlot_type()
{
    // prepare data:
    QVector<double> x3(2), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_type());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2;
    QVector<QString> labels;
    labels<<"leger"<<"lourd";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}

void MainWindow::on_stat_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
  MainWindow::makePlot_type();
}




void MainWindow::on_poids_2_textChanged(const QString &arg1)
{
    if (ui->poids_2->text().toFloat() < 8)
    {  ui->type_2->setCurrentText("leger");}
    else
          {  ui->type_2->setCurrentText("lourd");}
}




/*void MainWindow::on_camera_currentChanged(int index)
{
    c= new camera();
    c->show();

}
*/





void MainWindow::on_camera_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
    c= new camera();
    c->show();

}

void MainWindow::on_imprimer_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
    QString fileName = QFileDialog::getOpenFileName(0,"Open File",QString(),"PDF File(*.pdf)");

        QPrinter printer;
        QPrintDialog *imp = new QPrintDialog(&printer,0);

        if(imp->exec() == QDialog::Accepted)
        {
            QImage pdf(fileName);
            QPainter painter(&printer);
            painter.drawImage(QPoint(0,0),pdf);
            painter.end();
        }

        delete imp;
}



void MainWindow::on_tel_clicked()
{/*
    QString i = ui->call->text();
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select TEL from PASSAGERS WHERE upper(ID_PASAGER) like upper ('%"+i+"%')");*/
    //QDesktopServices::openUrl(QUrl("https://wa.me/+21658615958",QUrl::TolerantMode));
   // q.exec();
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
    QString i = ui->call->text();

    QString link = "https://wa.me/+216"+ i;
    QDesktopServices::openUrl(QUrl(link));

}

void MainWindow::on_sendsms_clicked()
{
    QSound s("C:/Users/chino/Downloads/click.wav");
        s.play();
    Smtp* smtp = new Smtp("anas.joo@esprit.tn",mail_pass, "smtp.gmail.com");


        smtp->sendMail("anas.joo@esprit.tn", "anas.joo@esprit.tn", ui->subject->text(),"");

        ui->subject->clear();
}



void MainWindow::on_pushButton_clicked()
{

     ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_login_clicked()
{

    QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();

        if(username == "ANAS" && password == "root")//||(username == "CRM" && password == "CRM"))
        {
            QMessageBox::information(this, "Login" , "Username and Password is correct");

            ui->stackedWidget->setCurrentIndex(2);



        }
        else
        {
            QMessageBox::warning(this, "Login", "Username and Password is not correct");
        }
}
void MainWindow::on_logout_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_gestionBagage_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retourner_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
