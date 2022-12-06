#include "vol.h"

#include "ui_vol.h"
#include "gestion_vol.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>




#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>

#include <QPixmap>
#include <QMediaPlayer>

#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>

#include<QString>
#include<QStatusBar>

#include <QSound>

#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include<QCamera>
#include <QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>

#include "gestion_vol.h"
#include "vol.h"
#include "ui_vol.h"
using namespace QtCharts;

QString rep;

Vol::Vol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vol)
{
    ui->setupUi(this);
    ui->lineEditid_vol->setValidator(new QIntValidator(0,9999999,this));
 /*   ui->lineEditdirection->setValidator(new QIntValidator('Milan','Barcelone','tokyo',this ));*/
    ui->tablevol->setModel(V.afficher());
    mCamera = new QCamera (this);
    mCameraViewfinder= new QCameraViewfinder(this);
    mCameraImageCapture= new QCameraImageCapture(mCamera,this);
    mLayout=new QVBoxLayout;
    mOpcionesMenu =new QMenu("Allumer",this);
mEncenderAction=new QAction("Ouvrir",this);
mApagarAction=new QAction("Eteindre",this);
mCapturarAction =new QAction ("Capturer",this);
mOpcionesMenu->addActions({mEncenderAction,mApagarAction,
                          mCapturarAction});
ui->opcionesPushButton->setMenu(mOpcionesMenu);
mCamera->setViewfinder(mCameraViewfinder);

mLayout->addWidget(mCameraViewfinder);
mLayout->setMargin(0);


ui->scrollArea->setLayout(mLayout);
connect(mEncenderAction,&QAction::triggered,[&]() {
    mCamera->start();

});
connect(mApagarAction,&QAction::triggered,[&]() {
    mCamera->stop();
});
connect(mCapturarAction, &QAction::triggered, [&]() {
   auto filename= QFileDialog::getSaveFileName(this,"Capturer","/",
                                 "Imagen(*.jpg;*.jpeg)");
   if (filename.isEmpty()) {
       return;
   }
   mCameraImageCapture->setCaptureDestination(
               QCameraImageCapture::CaptureToFile);
   QImageEncoderSettings imageEcoderSettings;
   imageEcoderSettings.setCodec("image/jpeg");
   imageEcoderSettings.setResolution(1600,1200);
   mCameraImageCapture->setEncodingSettings(imageEcoderSettings);
   mCamera->setCaptureMode(QCamera::CaptureStillImage);
   mCamera->start();
   mCamera->searchAndLock();
   mCameraImageCapture->capture(filename);
   mCamera->unlock();

});


}

Vol::~Vol()
{
    delete ui;

}



void Vol::on_pushButtonajouter_clicked()
{

    //bool test;
    QString ID_VOL=ui->lineEditid_vol->text();
    QString ARRIVE_VOL=ui->lineEditarrive_vol->text();
    QString DEPART_VOL=ui->lineEditdepart_vol->text();
    QString DIRECTION=ui->lineEditdirection->currentText();
    gestion_vol V(ID_VOL,ARRIVE_VOL,DEPART_VOL,DIRECTION);
    QMessageBox msg ;
    bool test=V.ajouter();
    if (test)
    { msg.setText("ajout par succes");
        ui->tablevol->setModel(V.afficher());
    }

    else {
        msg.setText("echec d'ajout");
        msg.exec();
    }
}

void Vol::on_pb_supprimer_clicked()
{
 gestion_vol V;
V.setID_VOL(ui->lineEditid->text());
bool  test=V.supprimer(V.getID_VOL());
QMessageBox msgBox;
if (test)
{
    msgBox.setText("Suppression avec succes.");
    ui->tablevol->setModel(V.afficher());
}else
 msgBox.setText("Echec de suppresion.");

msgBox.exec();

}

void Vol::on_date_dispo_modifier_clicked()
{

    QString ID_VOL=ui->ID_VOL_2->text();
    QString ARRIVE_VOL=ui->lineEditarrive->text();
    QString DEPART_VOL=ui->lineEditdepart->text();
    QString DIRECTION=ui->lineEditdirection_2->currentText();
     gestion_vol V(ID_VOL,ARRIVE_VOL,DEPART_VOL,DIRECTION);

    if (DIRECTION.isEmpty())
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir la direction vol."),QMessageBox::Cancel);
                 }
             else
             {
         bool test=V.modifier(ID_VOL);

         if (test)
                 { //Actualiser
             ui->tablevol->setModel(V.afficher());
                 QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                    QObject::tr("Modifier avec success ©\n"
                                                                "click cancel to exit."),QMessageBox::Cancel);
                 }
             else
                 QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                       QObject::tr("modification non effectué.\n"

                                           "click Cancel to exit."),QMessageBox::Cancel);
    }
    if (ARRIVE_VOL.isEmpty())
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir date d'arrivee vol."),QMessageBox::Cancel);
                 }
             else
             {
         bool test=V.modifier(ID_VOL);

         if (test)
                 { //Actualiser
             ui->tablevol->setModel(V.afficher());
                 QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                    QObject::tr("Modifier avec success ©\n"
                                                                "click cancel to exit."),QMessageBox::Cancel);
                 }
             else
                 QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                       QObject::tr("modification non effectué.\n"

                                           "click Cancel to exit."),QMessageBox::Cancel);}

if (DEPART_VOL.isEmpty())
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplirla date du depart du vol."),QMessageBox::Cancel);
             }
         else
         {
     bool test=V.modifier(ID_VOL);

     if (test)
             { //Actualiser
         ui->tablevol->setModel(V.afficher());
             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("Modifier avec success ©\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
             }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("modification non effectué.\n"

                                       "click Cancel to exit."),QMessageBox::Cancel);}
}




void Vol::on_rechercher_button_clicked()
{
    QString rech =ui->ID_VOL->text();
        ui->tablevol->setModel(V.rechercher(rech));
}

  // stat sur les NOM
    void Vol::on_statsmed_clicked()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from VOL where DIRECTION='Milan' ");
         int number1=model->rowCount();
         model->setQuery("select * from VOL where DIRECTION ='Barcelone' ");
         int number2=model->rowCount();
         model->setQuery("select * from VOL where DIRECTION='Newyork' ");
         int number3=model->rowCount(); // calculer le nombre de direction = ny
        model->setQuery("select * from VOL where DIRECTION='London' ");
              int number4=model->rowCount();
              model->setQuery("select * from VOL where DIRECTION ='Tokyo' ");
              int number5=model->rowCount();
         model->setQuery("select * from VOL where DIRECTION='Autre' ");
         int number6=model->rowCount();
         int total=number1+number2+number3+number4+number5+number6;
         QString a = QString("Milan"+QString::number((number1*100)/total,'f',2)+"%" );
         QString b = QString("Barcelone"+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString("Newyork"+QString::number((number3*100)/total,'f',2)+"%" );
         QString d = QString("London" +QString::number((number4*100)/total,'f',2)+"%" );
         QString e = QString("Tokyo" +QString::number((number5*100)/total,'f',2)+"%" );
         QString f = QString("Autre"+QString::number((number6*100)/total,'f',2)+"%" );


         QPieSeries *series = new QPieSeries();
         series->append(a,number1);
         series->append(b,number2);
         series->append(c,number3);
         series->append(d,number4);
         series->append(e,number5);
         series->append(f,number6);
         if (number1!= 0)
         {
             QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());
         }
         if (number2!=0)
         {
                  // Add label, explode and define brush for 2nd slice
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
         }
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
         if(number4!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice3 = series->slices().at(3);
                  //slice1->setExploded();
                  slice3->setLabelVisible();
         }
         if(number5!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice4 = series->slices().at(4);
                  //slice1->setExploded();
                  slice4->setLabelVisible();
         }
         if(number6!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice5 = series->slices().at(5);
                  //slice1->setExploded();
                  slice5->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle("Pourcentage Par DIRECTION:DIRECTION"+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();

    }

    void Vol::on_radioButton_croissant_clicked()
    {
         ui->tablevol->setModel(V.tri());
    }

    void Vol::on_radioButton_dcroissant_clicked()
    {
         ui->tablevol->setModel(V.trid());
    }
    void Vol::on_btn_imp_clicked()
    {
        QString strStream;
                                 QTextStream out(&strStream);

                                 const int rowCount = ui->tablevol->model()->rowCount();
                                 const int columnCount = ui->tablevol->model()->columnCount();
                                 QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                                 out <<"<html>\n"
                                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                     << "<title>ERP - COMmANDE LIST<title>\n "
                                     << "</head>\n"
                                     "<body bgcolor=#ffffff link=#5000A0>\n"
                                     "<h1 style=\"text-align: center;\"><strong> *****LISTE DES VOLS*****"+TT+" </strong></h1>"
                                     "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                       "</br> </br>";
                                 // headers
                                 out << "<thead><tr bgcolor=#d6e5ff>";
                                 for (int column = 0; column < columnCount; column++)
                                     if (!ui->tablevol->isColumnHidden(column))
                                         out << QString("<th>%1</th>").arg(ui->tablevol->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";

                                 // data table
                                 for (int row = 0; row < rowCount; row++) {
                                     out << "<tr>";
                                     for (int column = 0; column < columnCount; column++) {
                                         if (!ui->tablevol->isColumnHidden(column)) {
                                             QString data =ui->tablevol->model()->data(ui->tablevol->model()->index(row, column)).toString().simplified();
                                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                         }
                                     }
                                     out << "</tr>\n";
                                 }
                                 out <<  "</table>\n"
                                     "</body>\n"
                                     "</html>\n";

                                 QTextDocument *document = new QTextDocument();
                                 document->setHtml(strStream);

                                 QPrinter printer;

                                 QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                 if (dialog->exec() == QDialog::Accepted) {
                                     document->print(&printer);
                                 }

                                 delete document;


    }


/*
    void MainWindow::on_tableView_emploi_clicked(const QModelIndex &index)
    {
        QString mtrcl_emp = ui->tableView_emploi->model()->index(index.row(), 0).data().toString();
        ui->label_mtrcl_emploi->setText(mtrcl_emp);
    }

    void MainWindow::on_pushButton_emploi_goto_clicked()
    {
       QDate date = ui->dateEdit_emploi->date();
       ui->calendarWidget->setSelectedDate(date);
    }

    void MainWindow::on_dateTimeEdit_emploiS_dateTimeChanged()
    {
       dateTimeEditS_hadfocus  = true;
       dateTimeEditE_hadfocus  = false;
    }

    void MainWindow::on_dateTimeEdit_emploiE_dateTimeChanged()
    {
       dateTimeEditS_hadfocus  = false;
       dateTimeEditE_hadfocus  = true;
    }

    void MainWindow::on_pushButton_mdf_emploi_clicked()
    {
       QString mtrcl = ui->label_mtrcl_emploi->text();
       QString  DEPART_VOL = ui->dateTimeEdit_emploiS->text();
       QString  ARRIVE_VOL = ui->dateTimeEdit_emploiE->text();
       qDebug() << V.modifier_emploi(mtrcl, DEPART_VOL, ARRIVE_VOL);
    }*/

    void Vol::on_pb_envoyer_clicked()
    {


        gestion_vol p;
       p.setID_VOL(ui->le_id_chat->text());
        p.setDIRECTION(ui->le_message->text());
        QMessageBox msgbox;
        bool test=p.ajouterMessage(p.getID_VOL());
        if(test)
        {
            msgbox.setText("un nouveau message");
            ui->tab_message->setModel(p.afficherMessage());
        }
        else
            msgbox.setText("probleme d'envoie de message");
        msgbox.exec();

    }


    void Vol::on_pushButton_encrypt_clicked()
    {

        QString plainText = ui->plainTextEdit_plain->toPlainText();
        QString encryptedText = "to be implemented";

        if(ui->comboBox->currentIndex() == 0)
        {
            int key = ui->lineEdit_CC_key->text().toInt();
            encryptedText = ewCaesarCipher(plainText, key);
        }
        else if(ui->comboBox->currentIndex() == 1)
        {
            QString secret = ui->lineEdit_PF_Secret->text();
            encryptedText = ewPlayfair(plainText, secret);
        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            QString key = ui->lineEdit_DES_key_3->text();
            encryptedText = ewDES(plainText, key.toStdString());
        }
        else if(ui->comboBox->currentIndex() == 3)
        {
          double p = ui->RSA_lineEdit_p_2->text().toDouble();
          double q = ui->RSA_lineEdit_q_2->text().toDouble();
           double dbl = ewRSA(plainText.toDouble(), p, q);

            std::ostringstream strs;
            strs << dbl;
            encryptedText = QString::fromStdString(strs.str());

            std::pair<double, double> pair = RSAKeys(p, q);
            std::ostringstream strPrK;
            strPrK << pair.first;
            ui->RSA_lineEdit_prkey_2->setText(QString::fromStdString(strPrK.str()));
            std::ostringstream strPuK;
            strPuK << pair.second;
          ui->RSA_lineEdit_pukey_2->setText(QString::fromStdString(strPuK.str()));
        }
        else if(ui->comboBox->currentIndex() == 4)
        {
            QString key = ui->lineEdit_rc4_key_3->text();
            encryptedText = ewRC4(plainText, key);
        }
        else if(ui->comboBox->currentIndex() == 5)
        {
            QString key = ui->lineEdit_DES_key_3->text();
            encryptedText = ewIDES(plainText, key.toStdString());
        }
        ui->plainTextEdit_encrypted->document()->setPlainText(encryptedText);
    }

    void Vol::on_pushButton_decrypt_clicked()
    {
        QString encryptedText = ui->plainTextEdit_encrypted->toPlainText();
        QString plainText = "to be implemented";

        if(ui->comboBox->currentIndex() == 0)
        {
            int key = ui->lineEdit_CC_key->text().toInt();
            plainText = dwCaesarCipher(encryptedText, key);
        }
        else if(ui->comboBox->currentIndex() == 1)
        {
            QString secret = ui->lineEdit_PF_Secret->text();
            plainText = dwPlayfair(encryptedText, secret);
        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            QString key = ui->lineEdit_DES_key_3->text();
            plainText = dwDES(encryptedText, key.toStdString());
        }
        else if(ui->comboBox->currentIndex() == 3)
        {
           double p = ui->RSA_lineEdit_p_2->text().toDouble();
         double q = ui->RSA_lineEdit_q_2->text().toDouble();

            std::ostringstream pstr;
            pstr << dwRSA(encryptedText.toDouble(), p, q);
            plainText = QString::fromStdString(pstr.str());
        }
        else if(ui->comboBox->currentIndex() == 4)
        {
            QString key = ui->lineEdit_rc4_key_3->text();
            plainText = dwRC4(encryptedText, key);
        }
        else if(ui->comboBox->currentIndex() == 5)
        {
            QString key = ui->lineEdit_DES_key_3->text();
            plainText = dwIDES(encryptedText, key.toStdString());
        }
        ui->plainTextEdit_plain->document()->setPlainText(plainText);
    }

    void Vol::on_actionReset_Fields_triggered()
    {
        ui->plainTextEdit_plain->clear();
        ui->plainTextEdit_encrypted->clear();
        ui->lineEdit_CC_key->clear();
    }

    void Vol::on_actionClear_Plain_Text_triggered()
    {
        ui->plainTextEdit_plain->clear();
    }

    void Vol::on_actionClear_Encrypted_Text_triggered()
    {
        ui->plainTextEdit_encrypted->clear();
    }

    void Vol::on_actionExit_triggered()
    {
        exit(0);
    }

    void Vol::on_actionAbout_Qt_triggered()
    {
        QMessageBox::aboutQt(this);
    }

    void Vol::on_comboBox_currentTextChanged(const QString &arg1)
    {
        if(arg1 == "Caesar Cipher")
        {
            ui->stackedWidget_3->setCurrentIndex(0);
        }
        else if(arg1 == "Playfair")
        {
            ui->stackedWidget_3->setCurrentIndex(1);
        }
        else if(arg1 == "DES")
        {
            ui->stackedWidget_3->setCurrentIndex(2);
        }
        else if(arg1 == "RSA")
        {
            ui->stackedWidget_3->setCurrentIndex(3);
        }
        else if(arg1 == "RC4")
        {
            ui->stackedWidget_3->setCurrentIndex(4);
        }
        else if(arg1 == "DES with Text")
        {
            ui->stackedWidget_3->setCurrentIndex(2);
        }
    }





    // Caesar Cipher Methods

    QString Vol::ewCaesarCipher(QString plainText, int key)
    {
        std::string result = "";
        std::string plainStdText = plainText.toStdString();

        for (int i=0;i<plainText.length();i++)
        {
            if(plainStdText[i] == ' ')
            {
                result += ' ';
            }
            else if(std::isalpha(plainStdText[i]))
            {
                if (std::isupper(plainStdText[i]))
                    result += char(int(plainStdText[i]+key-65)%26 +65);
                else
                    result += char(int(plainStdText[i]+key-97)%26 +97);
            }
        }

        return QString::fromStdString(result);
    }

    QString Vol::dwCaesarCipher(QString encryptedText, int key)
    {
        return ewCaesarCipher(encryptedText, 26-key);
    }





    // playfair Methods

    QString Vol::ewPlayfair(QString plainText, QString secret)
    {
        std::string plainStdText = plainText.toStdString();
        std::string secretStdText = secret.toStdString();

        normalizePFSecret(secretStdText);
        populatePFMatrix(secretStdText);
        normalizePFString(plainStdText);

        std::string encryptedText = encryptPFString(plainStdText);

        return QString::fromStdString(encryptedText);
    }

    QString Vol::dwPlayfair(QString encryptedText, QString secret)
    {
        std::string encryptedStdText = encryptedText.toStdString();
        std::string secretStdText = secret.toStdString();

        normalizePFSecret(secretStdText);
        populatePFMatrix(secretStdText);

        std::string plainText = decryptPFString(encryptedStdText);

        return QString::fromStdString(plainText);
    }

    bool Vol::inSameRow(Position p1, Position p2)
    {
        if(p1.x == p2.x)
            return true;
        return false;
    }

    bool Vol::inSameColumn(Position p1, Position p2)
    {
        if(p1.y == p2.y)
            return true;
        return false;
    }

    void Vol::normalizePFString(std::string &str)
    {
        std::string pure_str= "";
        // remove any non-alphabetical characters
        // convert string to lower case
        for(int i=0;i<str.size();++i)
        {
            if(isalpha(str[i]))
            {
                if(std::isupper(str[i]))
                    str[i] = std::tolower(str[i]);
                pure_str += str[i];
            }
        }

        // separate duplicate characters
        for(int i=0 ; i<pure_str.size()-1 ; i+=2)
        {
            if(pure_str[i] == pure_str[i+1])
                pure_str.insert(pure_str.begin()+i+1, 'x');
        }

        // make string even
        if(pure_str.size()%2 !=0)
            pure_str += 'x';

        str = pure_str;
    }

    std::string Vol::encryptPFString(std::string plainStdText)
    {
        std::string result = "";

        for(int i=0;i<plainStdText.size(); i+=2)
        {
            Position p1 = findPositionByChar(plainStdText[i]);
            Position p2 = findPositionByChar(plainStdText[i+1]);

            if(inSameRow(p1, p2))
            {
                if(p1.y == 4)
                    p1.y = 0;
                else
                    p1.y +=1;

                if(p2.y == 4)
                    p2.y = 0;
                else
                    p2.y +=1;

                result += findCharByPosition(p1);
                result += findCharByPosition(p2);
            }
            else if(inSameColumn(p1, p2))
            {
                if(p1.x == 4)
                    p1.x = 0;
                else
                    p1.x +=1;

                if(p2.x == 4)
                    p2.x = 0;
                else
                    p2.x +=1;

                result += findCharByPosition(p1);
                result += findCharByPosition(p2);
            }
            else
            {
                Position t1, t2;

                t1.x = p1.x;
                t1.y = p2.y;

                t2.x = p2.x;
                t2.y = p1.y;

                result += findCharByPosition(t1);
                result += findCharByPosition(t2);
            }
        }

        return result;
    }

    std::string Vol::decryptPFString(std::string encryptedStdText)
    {
        std::string result = "";

        for(int i=0;i<encryptedStdText.size(); i+=2)
        {
            Position p1 = findPositionByChar(encryptedStdText[i]);
            Position p2 = findPositionByChar(encryptedStdText[i+1]);

            if(inSameRow(p1, p2))
            {
                if(p1.y == 0)
                    p1.y = 4;
                else
                    p1.y -=1;

                if(p2.y == 0)
                    p2.y = 4;
                else
                    p2.y -=1;

                result += findCharByPosition(p1);
                result += findCharByPosition(p2);
            }
            else if(inSameColumn(p1, p2))
            {
                if(p1.x == 0)
                    p1.x = 4;
                else
                    p1.x -=1;

                if(p2.x == 0)
                    p2.x = 4;
                else
                    p2.x -=1;

                result += findCharByPosition(p1);
                result += findCharByPosition(p2);
            }
            else
            {
                Position t1, t2;

                t1.x = p1.x;
                t1.y = p2.y;

                t2.x = p2.x;
                t2.y = p1.y;

                result += findCharByPosition(t1);
                result += findCharByPosition(t2);
            }
        }

        return result;
    }

    void Vol::normalizePFSecret(std::string &secret)
    {
        std::string result = "";
        secret += "abcdefghiklmnopqrstuvwxyz";
        for(int i=0;i<secret.size();++i)
        {
            if(result.find(secret[i]) == std::string::npos)
                result += secret[i];
        }
        secret = result;
    }

    void Vol::populatePFMatrix(std::string secret)
    {
        for(int i=0; i<5; ++i)
        {
            for(int j=0; j<5 ; ++j)
            {
                pfMatrix[i][j] = secret[j+5*i];
            }
        }
    }

    Position Vol::findPositionByChar(char ch)
    {
        Position p;

        for(int i=0; i<5; ++i)
        {
            for(int j=0; j<5; ++j)
            {
                if(pfMatrix[i][j] == ch)
                {
                    p.x = i;
                    p.y = j;
                }
            }
        }

        return p;
    }

    char Vol::findCharByPosition(Position p)
    {
        return pfMatrix[p.x][p.y];
    }





    // data 0000000100100011010001010110011110001001101010111100110111101111
    // key  0001001100110100010101110111100110011011101111001101111111110001

    // DES Methods

    QString Vol::ewDES(QString plainText, std::string key)
    {
        std::vector< std::string > keys = keyPreparation(key);

        QString encryptedText = DESEncryption(plainText.toStdString(), keys);

        return encryptedText;
    }

    QString Vol::dwDES(QString encryptedText, std::string key)
    {
        std::vector< std::string > keys = keyPreparation(key);

        std::reverse(keys.begin(), keys.end());

        QString plainText = DESEncryption(encryptedText.toStdString(), keys);

        return plainText;
    }

    std::vector< std::string > Vol::keyPreparation(std::string key)
    {
        // 0001001100110100010101110111100110011011101111001101111111110001

        std::string permutedKey = "";
        int PC1_permutations[56] = {
            57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
        };

        for(int i=0;i<56; ++i)
        {
            permutedKey += key[PC1_permutations[i]-1];
        }

    //    std::cout << key << std::endl;
    //    std::cout << permutedKey << std::endl;
    //    std::cout << permutedKey.length() << std::endl;


        int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

        std::vector< std::pair<std::string, std::string> > keys;

        std::string C0 = permutedKey.substr(0,28);
        std::string D0 = permutedKey.substr(28,56);

    //    std::cout << "C0 : " << C0 << std::endl;
    //    std::cout << "D0 : " << D0 << std::endl;

        keys.push_back(std::make_pair(C0, D0));

        for(int i=1 ; i<17 ; ++i)
        {
            std::string C = keys[i-1].first;
            std::string D = keys[i-1].second;

            C = C.substr(shifts[i-1], C.length()) + C.substr(0, shifts[i-1]);
            D = D.substr(shifts[i-1], D.length()) + D.substr(0, shifts[i-1]);

            keys.push_back(std::make_pair(C, D));

    //        std::cout << "C" << i << " : " << C << std::endl;
    //        std::cout << "D" << i << " : " << D << std::endl;
        }


        int PC2_permutations[48] = {
            14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
        };

        std::vector<std::string> finalKeys;

        for(int i=0;i<16;++i)
        {
            std::string k = keys[i+1].first + keys[i+1].second;
            std::string fk = "";

            for(int j=0;j<48;++j)
            {
                fk += k[PC2_permutations[j]-1];
            }
            finalKeys.push_back(fk);
    //        std::cout << fk << std::endl;
        }

        std::cout << std::endl << ">[BEGIN] Keys generated Successfully" << std::endl << std:: endl;

        for(int i=0; i<finalKeys.size(); ++i)
        {
            std::cout << "Key " << i+1 << ": " << finalKeys[i] << std::endl;
        }

        std::cout << std::endl << ">[END] Keys generated Successfully" << std::endl << std:: endl;


        return finalKeys;
    }

    QString Vol::DESEncryption(std::string dataBlock, std::vector< std::string > keys)
    {
        // 0000000100100011010001010110011110001001101010111100110111101111

        std::string permutedBlock = "";

        int initPermutation[64] = {
            58,    50,   42,    34,    26,   18,    10,    2,
            60,    52,   44,    36,    28,   20,    12,    4,
            62,    54,   46,    38,    30,   22,    14,    6,
            64,    56,   48,    40,    32,   24,    16,    8,
            57,    49,   41,    33,    25,   17,     9,    1,
            59,    51,   43,    35,    27,   19,    11,    3,
            61,    53,   45,    37,    29,   21,    13,    5,
            63,    55,   47,    39,    31,   23,    15,    7
        };

        for(int i=0 ; i<64 ; ++i)
        {
            permutedBlock += dataBlock[initPermutation[i]-1];
        }

        std::string L0 = permutedBlock.substr(0, 32);
        std::string R0 = permutedBlock.substr(32, 64);


        std::cout << "L0 : " << L0 << std::endl;
        std::cout << "R0 : " << R0 << std::endl;

        std::vector< std::pair<std::string, std::string> > data;
        data.push_back(std::make_pair(L0, R0));

        for(int i=1;i<17;++i)
        {
            std::string L = data[i-1].second;

            std::string R = apply_xor(
                data[i-1].first,
                apply_func_F(apply_func_E(data[i-1].second), keys[i-1])
            );

            data.push_back(std::make_pair(L, R));

            std::cout << "L" << i << " : " << L << std::endl;
            std::cout << "R" << i << " : " << R << std::endl;
        }

        std::string encryptedDataReversedKey = "";
        encryptedDataReversedKey += data[data.size()-1].second;
        encryptedDataReversedKey += data[data.size()-1].first;

        std::string finalPermutedBlock = "";

        int finalPermutation[64] = {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41,  9, 49, 17, 57, 25
        };

        for(int i=0 ; i<64 ; ++i)
        {
            finalPermutedBlock += encryptedDataReversedKey[finalPermutation[i]-1];
        }

        return QString(finalPermutedBlock.c_str());
    }

    std::string Vol::apply_xor(std::string str1, std::string str2)
    {
        if(str1.length() != str2.length())
            std::cout << "Error in XORed Strings, Length Not Equal" << std::endl;

        std::string result = "";
        for(int i=0;i<str1.length();++i)
        {
            if(str1[i] == str2[i])
                result += '0';
            else
                result += '1';
        }

        return result;
    }

    std::string Vol::apply_func_F(std::string str1, std::string str2)
    {
        // result is 48 bit
        std::string result = apply_xor(str1, str2);

        int sboxes[8][4][16] =
        {
            {
                { 14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7 },
                {  0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8 },
                {  4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0 },
                { 15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13 }
            },
            {
                { 15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10 },
                {  3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5 },
                {  0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15 },
                { 13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9 }
            },
            {
                { 10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8 },
                { 13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1 },
                { 13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7 },
                {  1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12 }
            },
            {
                {  7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15 },
                { 13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9 },
                { 10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4 },
                {  3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14 }
            },
            {
                {  2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9 },
                { 14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6 },
                {  4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14 },
                { 11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3 }
            },
            {
                { 12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11 },
                { 10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8 },
                {  9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6 },
                {  4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13 }
            },
            {
                {  4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1 },
                { 13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6 },
                {  1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2 },
                {  6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12 }
            },
            {
                { 13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7 },
                {  1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2 },
                {  7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8 },
                {  2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11 }
            }
        };

        std::string output = "";
        std::string outerBits = "";
        std::string innerBits = "";

        for(int i=0, s=0 ; i<48 ; i+=6, s++)
        {
            outerBits += result[i];
            outerBits += result[i+5];

            innerBits += result[i+1];
            innerBits += result[i+2];
            innerBits += result[i+3];
            innerBits += result[i+4];

            int row = std::stoi(outerBits, nullptr, 2);
            int column = std::stoi(innerBits, nullptr, 2);

            int valInSBox = sboxes[s][row][column];

            output += std::bitset<4>(valInSBox).to_string();

            outerBits = "";
            innerBits = "";
        }

        std::string permutedOutput = "";

        int permutations[32] = {
            16,  7, 20, 21,
            29, 12, 28, 17,
             1, 15, 23, 26,
             5, 18, 31, 10,
             2,  8, 24, 14,
            32, 27,  3,  9,
            19, 13, 30,  6,
            22, 11,  4, 25
        };

        for(int i=0; i<32; ++i)
        {
            permutedOutput += output[permutations[i]-1];
        }

        return permutedOutput;
    }

    std::string Vol::apply_func_E(std::string str)
    {
        std::string result = "";

        int ePermutations[48] = {
             32,     1,    2,     3,     4,    5,
              4,     5,    6,     7,     8,    9,
              8,     9,   10,    11,    12,   13,
             12,    13,   14,    15,    16,   17,
             16,    17,   18,    19,    20,   21,
             20,    21,   22,    23,    24,   25,
             24,    25,   26,    27,    28,   29,
             28,    29,   30,    31,    32,    1
        };

        for(int i=0;i<48;++i)
        {
            result += str[ePermutations[i]-1];
        }

        return result;
    }


    // improved DES with text Methods
    QString Vol::ewIDES(QString plainText, std::string key)
    {
        std::vector< std::string > keys = keyPreparation(key);
        std::vector< std::string > blocks = textToBinaryAscii(plainText.toStdString());

        QString encryptedText;

        for(int i=0; i<blocks.size(); ++i)
            encryptedText += DESEncryption(blocks[i], keys);

    //    encryptedText = QString::fromStdString(binaryAsciiToText(encryptedText.toStdString()));

        return encryptedText;
    }

    QString Vol::dwIDES(QString encryptedText, std::string key)
    {
        std::vector< std::string > keys = keyPreparation(key);
        std::reverse(keys.begin(), keys.end());

        std::string stdPlainText = encryptedText.toStdString();
        std::string allPlainText = "";

        for(int i=0; i<encryptedText.size()/64; ++i)
        {
            allPlainText += DESEncryption(stdPlainText.substr(i*64, 64), keys).toStdString();
        }

        return QString::fromStdString(binaryAsciiToText(allPlainText));
    }

    std::vector< std::string > Vol::textToBinaryAscii(std::string str)
    {
        std::vector< std::string > blocksOfData;

        for(int i=0; i<str.size()/8; ++i)
        {
            std::string blockStr = str.substr(i*8, 8);
            std::string block = "";

            for(int i=0; i<8; ++i)
                block += charToBinaryAscii(blockStr[i]);

            blocksOfData.push_back(block);
        }

        if(str.size()%8 != 0)
        {
            int start = ((int)str.size()/8)*8;
            int length = (int)str.size()- start;

            std::string blockStr = str.substr(start, length);
            for(int i=0; i<(8-length); ++i)
                blockStr += " ";

            std::string block = "";
            for(int i=0; i<8; ++i)
                block += charToBinaryAscii(blockStr[i]);
            blocksOfData.push_back(block);
        }

        return blocksOfData;
    }

    std::string Vol::binaryAsciiToText(std::string str)
    {
        std::string blocksOfData = "";

        for(int i=0; i<str.size()/64; ++i)
        {
            std::string blockStr = str.substr(i*64, 64);
            std::string block = "";

            for(int i=0; i<8; ++i)
            {
               std::string ascii = blockStr.substr(i*8, 8);
               block += binaryAsciiToChar(ascii);
            }
            blocksOfData += block;
        }

        return blocksOfData;
    }

    std::string Vol::charToBinaryAscii(char ch)
    {
        return std::bitset<8>(int(ch)).to_string();
    }

    char Vol::binaryAsciiToChar(std::string binaryAscii)
    {
        return char(std::bitset<8>(binaryAscii).to_ulong());
    }





    // RSA Methods

    double Vol::ewRSA(double msg, double p, double q)
    {
        // generate public as first, private as second key
        std::pair<double,double> keys = RSAKeys(p, q);

        double n = p*q;
        double e = keys.first;

        return RSAEncryption(msg, n, e);
    }

    double Vol::dwRSA(double msg, double p, double q)
    {
        // generate public as first, private as second key
        std::pair<double,double> keys = RSAKeys(p, q);

        int n = p*q;
        int d = keys.second;

        return RSADecryption(msg, n, d);
    }

    double Vol::RSAEncryption(double msg, double n, double e)
    {
        // Encryption c = (msg ^ e) % n
        double c = pow(msg, e);
        c = fmod(c, n);
        return c;
    }

    double Vol::RSADecryption(double msg, double n, double d)
    {
        // Decryption m = (c ^ d) % n
        double m = pow(msg, d);
        m = fmod(m, n);
        return m;
    }

    std::pair<double, double> Vol::RSAKeys(double p, double q)
    {
        // Finding public key; e stands for encrypt.
        double e = 2;
        double phi = (p-1)*(q-1);
        while (e < phi)
        {
            // e must be co-prime to phi and
            // smaller than phi.
            if (gcd(e, phi)==1)
                break;
            else
                e++;
        }

        // Private key (d stands for decrypt)
        // choosing d such that it satisfies
        // d*e = 1 + k * totient

        int d = e;
        while((int)(d*e)%((int)phi) != 1)
        {
            d++;
        }

        return std::make_pair(e, d);
    }

    int Vol::gcd(int a, int h)
    {
        int temp;
        while (1)
        {
            temp = a%h;
            if (temp == 0)
              return h;
            a = h;
            h = temp;
        }
    }





    // RC4 Methods

    QString Vol::ewRC4(QString msg, QString key)
    {
        std::vector<int> k;

        // initialize key
        std::string stdCppKey = key.toStdString();
        for(int i=0; i<stdCppKey.length(); ++i)
            k.push_back(int(stdCppKey[i] - '0'));

        std::vector<int> s(256);
        std::vector<int> t(256);

        // initialize vector S to [0:255]
        for(int i=0; i<256; ++i)
            s[i] = i;

        // initialize vector T from key K
        for(int i=0; i<256; ++i)
            t[i] = k[i%k.size()];

        // initial Permutation Of S
        int j = 0;
        for(int i=0; i<256; ++i)
        {
            j = (j + s[i] + t[i])%256;
            std::swap(s[i], s[j]);
        }

        // prepare msg
        std::vector< std::bitset<8> > msg_bytes = bytesOfMessage(msg.toStdString());


        // generate a key for each byte of input
        // e.g input: 5 bytes, generates output: 5 bytes
        std::vector< std::bitset<8> > keys = keysGenerator((int)msg_bytes.size(), s);

        return RC4Encryption(msg_bytes, keys);

    }

    QString Vol::dwRC4(QString msg, QString key)
    {
        return ewRC4(msg, key);
    }

    QString Vol::RC4Encryption(std::vector< std::bitset<8> > msg_bytes, std::vector< std::bitset<8> > keys)
    {
        std::string result = "";
        for (int i = 0; i < msg_bytes.size(); ++i)
        {
            std::bitset<8> temp = std::bitset<8>(msg_bytes[i] ^ keys[i]);
            result += temp.to_string();
        }

        // Debugging output
        std::cout << "> Debugging Statements" << std::endl;

        std::cout << "I/P: " ;
        for(int t=0; t<msg_bytes.size(); ++t)
            std::cout << msg_bytes[t];
        std::cout << std::endl;

        std::cout << "Key: ";
        for(int t=0; t<keys.size(); ++t)
            std::cout << keys[t].to_string();
        std::cout << std::endl;
        std::cout << "O/P: " << result << std::endl;

        return QString::fromStdString(result);
    }

    std::vector< std::bitset<8> > Vol::keysGenerator(int msg_length, std::vector<int> s)
    {
        std::vector< std::bitset<8> > keys(msg_length);

        int i=0, j=0, k=0;
        for (int lc = 0; lc < msg_length; ++lc)
        {
            i = (i+1)%256;
            j = (j+s[i])%256;
            std::swap(s[i], s[j]);
            k = s[(s[i]+s[j])%256];
            keys[lc] = std::bitset<8>(k);
        }

        return keys;
    }

    std::vector< std::bitset<8> > Vol::bytesOfMessage(std::string msg)
    {
        std::vector< std::bitset<8> > msg_bytes;

        for(int i=0; i<(msg.length()/8); ++i)
        {
            std::string msg_byte = "";
            for(int j=0; j<8; ++j)
            {
                int idx = j + i*8;
                msg_byte += msg[idx];
            }
            msg_bytes.push_back(std::bitset<8>(msg_byte));
        }

        return msg_bytes;
    }





