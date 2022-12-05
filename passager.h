#ifndef PASSAGER_H
#define PASSAGER_H

#include <QMainWindow>
#include "gestion_passager.h"
#include "stat.h"
#include "stat_combo.h"
#include "smtp.h"
#include <QDebug>
#include <QDialog>
#include "arduino.h"

namespace Ui {
class Passager;
}

class Passager : public QDialog
{
    Q_OBJECT

public:
    explicit Passager(QWidget *parent = nullptr);
    ~Passager();

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


    void on_retourner_clicked();

private:
    Ui::Passager *ui;
 gestion_passager P;
   stat_combo *s;
 QStringList files;

//Arduino
 QByteArray data;

 Arduino A; // objet temporaire
 QSqlDatabase test_bd;

};
#endif // PASSAGER_H
