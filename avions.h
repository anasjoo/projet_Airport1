#ifndef AVIONS_H
#define AVIONS_H

#include <QDialog>
#include"avion.h"
#include "avion.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTableView>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QPieSlice>


namespace Ui {
class Avions;
}

class Avions : public QDialog
{
    Q_OBJECT

public:
    explicit Avions(QWidget *parent = nullptr);
    ~Avions();
private slots:

    void on_pbajouter_clicked();

    void on_pbajouter_2_clicked(); //button modifier

    void on_pbajouter_3_clicked(); //button afficher

    void on_pbajouter_10_clicked(); //button trier

    void on_pbajouter_12_clicked(); // button stat

    void on_LE_Chercher_textChanged(const QString &arg1);
    void on_pushButton_Supp_clicked();


   // void on_pbajouter_11_clicked();

    void on_retourner_clicked();

private:
    Ui::Avions *ui;
    avion a;

};

#endif // AVIONS_H
