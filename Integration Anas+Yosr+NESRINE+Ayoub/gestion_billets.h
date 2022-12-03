#ifndef GESTION_BILLETS_H
#define GESTION_BILLETS_H
#include <QDialog>
#include "billet.h"
#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include "smtp.h"
#include "arduino.h"
namespace Ui {
class gestion_billets;
}

class gestion_billets : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_billets(QWidget *parent = nullptr);
    ~gestion_billets();
private slots :
    void update_label() ;

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



private:
    Ui::gestion_billets *ui;
    Billet Etmp;
    QTcpSocket *socket ;
    QStringList files ;
    Arduino A1 ; // objet tempo
         QByteArray data ; //var contenant les donnees reçues
};

#endif // GESTION_BILLETS_H
