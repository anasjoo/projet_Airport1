#ifndef MAINWINDOWAYOUB_H
#define MAINWINDOWAYOUB_H
#include "billet.h"
#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include "smtp.h"
#include "arduino.h"

namespace Ui {
class mainwindowayoub;
}

class mainwindowayoub : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowayoub(QWidget *parent = nullptr);
    ~mainwindowayoub();
private slots:
    void update_label1() ;

    void on_button_ajouter_clicked();

    void on_pbSupprimer_clicked();

    void on_updateBP_clicked();

    void on_pushButton_clicked();

    void on_recher_clicked();

    //void on_trier_clicked();
           void sendMail();
           void mailSent(QString);
           void browse();

           void on_pb_code_clicked();

           void on_pb_excel_clicked();

           void on_retourner_clicked();

private:
    Ui::mainwindowayoub *ui;
    Billet Etmp;
    QTcpSocket *socket ;
    QStringList files ;
    Arduino A1 ; // objet tempo
         QByteArray data ; //var contenant les donnees reçues
};

#endif // MAINWINDOWAYOUB_H
