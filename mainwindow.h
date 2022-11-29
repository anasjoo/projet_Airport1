#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passager.h"
#include "stat_combo.h"

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
    void on_pushButton_Ajouter_clicked();






    void on_pushButton_Supp_clicked();

    void on_pushButton_Modifier_clicked();






void on_LE_Chercher_textChanged(const QString &arg1);


    void on_comboBox_Tri_currentIndexChanged(const QString &arg1);


    void on_pushButton_PDF_clicked();


    void on_stat_clicked();




void on_pushButton_envoyer_clicked();

void on_pushButton_imprimer_clicked();

//Arduino
    void update_label();


private:
    Ui::MainWindow *ui;
   Passager P;

   stat_combo *s;
 QStringList files;

//Arduino
 QByteArray data;
 arduino A;
 QSqlDatabase test_bd;

};

#endif // MAINWINDOW_H
