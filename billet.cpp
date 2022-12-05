#include "billet.h"
#include<QtDebug>
#include <QSqlQuery>
/********************** ta3 pdf ***************/
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include<QFile>
#include<QFileDialog>
//#include <QMessNUMSBox>
#include <QSslSocket>
#include <QAbstractSocket>
Billet::Billet()
{
  id=0;
  NUMV=0;  // inisalisation
  NUMS=0;


}

Billet::Billet(int id,int NUMV,int NUMS){
    this->id=id;                           //lezem n3abehom
    this->NUMV=NUMV;
    this->NUMS=NUMS;

}

int Billet::getId(){
    return id;
}
int Billet::getNUMV(){
    return NUMV;
}
int Billet::getNUMS(){
    return NUMS;
}
void Billet::setId(int id){
    this->id=id;
}

void Billet::setNUMS(int NUMS){
    this->NUMS=NUMS;
}
void Billet::setNUMV(int NUMV){
    this->NUMV=NUMV;
}


bool Billet::ajouter()
{
  QSqlQuery query;
  QString id_string= QString::number(id);
  QString NUMV_string= QString::number(NUMV);
  QString NUMS_string= QString::number(NUMS);

        query.prepare("INSERT INTO BILLET(ID,NUMV,NUMS) "
                      "VALUES (:ID,:NUMV,:NUMS)");
        query.bindValue(":ID", id_string);
          query.bindValue(":NUMV", NUMV_string);
           query.bindValue(":NUMS", NUMS_string);


       return query.exec();

}

QSqlQueryModel * Billet::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BILLET");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUMV"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUMS"));

    return model;
    }
bool Billet::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM BILLET WHERE ID = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool Billet::update(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE BILLET SET ID= :id,NUMV= :NUMV,NUMS = :NUMS WHERE ID = :id");
    query.bindValue(":id",res);

     query.bindValue(":NUMV",NUMV);
      query.bindValue(":NUMS",NUMS);
    return query.exec();
}
QSqlQueryModel* Billet::trier(QString nom)

 {

    QSqlQueryModel* model = new QSqlQueryModel();

        if (nom=="id")

        {
        model->setQuery("select * from billet  order by  cin asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMV"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));

    }
       if (nom=="id")
    {model->setQuery("select *FROM BILLET ORDER BY ID ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMV"));

           model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
    }
    return model;
    }
    QSqlQueryModel* Billet::trier2(QString nom)
      {

         QSqlQueryModel* model=new QSqlQueryModel() ;

         if (nom=="NUMV")
      {model->setQuery("select *FROM billet ORDER BY id DESC");
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMV"));

                model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));

      }
         if (nom=="NUMV")

         {
         model->setQuery("select * from billet  order by  id desc");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMV"));

         model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));

    }
          return model ;


}

void Billet::CREATION_PDF()

{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())

        { fileName.append(".pdf"); }



    QPrinter printer(QPrinter::PrinterResolution);

    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPaperSize(QPrinter::A4);

    printer.setOutputFileName(fileName);



    QTextDocument doc;

    QSqlQuery q;

    q.prepare("SELECT * FROM BILLETS ");

    q.exec();

    QString pdf="<br> <h1  style='color:blue'>LISTE DES BILLETS  <br></h1>\n <br> <table>  <tr>  <th>ID </th> <th>NUMS </th> <th>NUMV  </th>  </tr>" ;

//br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //



    while ( q.next())

        {



        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;

    }

    doc.setHtml(pdf);

    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the pNUMS number

    doc.print(&printer);





}

QSqlQueryModel* Billet::rechercheC(int id){
QSqlQueryModel* model=new QSqlQueryModel() ;
QString id_string = QString::number(id);
QString NUMV_string= QString::number(NUMV);
QString NUMS_string= QString::number(NUMS);

model->setQuery("select * from billet where ID='"+id_string+"'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMV"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));



return model;
}

