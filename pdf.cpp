#include "pdf.h"
#include "ui_pdf.h"
#include <QtPrintSupport/QPrinter>
#include<QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include "mainwindow_Bagage.h"
#include "ui_mainwindow_Bagage.h"
#include "bagages.h"
#include <QSqlQuery>
pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushpdf_clicked()
{
    QPdfWriter pdf("C:/Users/chino/Desktop/bagage.pdf");
        QPainter painter(&pdf);
        QImage imagen("C:/Users/chino/Desktop/bagage");
        painter.setPen(Qt::black);
        QString id = ui->lineEdit->text();
        QSqlQuery test ;
        test.prepare("SELECT COUNT(*) from BAGAGES where ID_BAGAGE= :id");
        test.bindValue(":id",id);
        test.exec();
        if (test.next())
        {
      if (test.value(0).toInt() == 1)
      {
        QSqlQuery query ;
        query.prepare("select ID_BAGAGE,POIDS,TYPE, ID_PASSAGER from BAGAGES where ID_BAGAGE= :id");
        query.bindValue(":id",id);
        query.exec();
        if (query.next())
        {
        QString idbagage = query.value(0).toString();
        //float  poids = query.value(1).toFloat();
        QString type = query.value(2).toString();
        QString idpassager = query.value(3).toString();
        painter.drawImage(40,40,imagen);
        //painter.drawText(100,300,"successfully export to PDF :) ");
        painter.drawText(1000,1500,"ID BAGAGE: ");
        painter.drawText(2000,1500,idbagage);
      //  painter.drawtext(100,700,poids);
        painter.drawText(1000,1800,"TYPE BAGAGE: ");
        painter.drawText(2000,1800,type);
        painter.drawText(1000,2100,"ID PASSAGER: ");
        painter.drawText(2000,2100,idpassager);

        painter.end();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("pdf done.\n"
                                             "Click ok to exit."), QMessageBox::Ok);
        }
     }
      else
      {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("pdf not done.\n"
                                              "Click ok to exit."), QMessageBox::Ok);
      }
      }
    }


