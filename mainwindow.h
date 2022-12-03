#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "billet.h"
#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include "smtp.h"
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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
    Ui::MainWindow *ui;
     Billet Etmp;
     QTcpSocket *socket ;
     QStringList files ;
     arduino A1 ; // objet tempo
          QByteArray data ; //var contenant les donnees reçues
};

#endif // MAINWINDOW_H
