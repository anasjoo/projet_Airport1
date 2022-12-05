#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"avion.h"
#include <QMainWindow>

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

    void on_pbajouter_clicked();

    void on_pbajouter_2_clicked(); //button modifier

    void on_pbajouter_3_clicked(); //button afficher

    void on_pbajouter_10_clicked(); //button trier

    void on_pbajouter_12_clicked(); // button stat

    void on_LE_Chercher_textChanged(const QString &arg1);
    void on_pushButton_Supp_clicked();


    void on_id_2_cursorPositionChanged(int arg1, int arg2);

   // void on_pbajouter_11_clicked();

private:
    Ui::MainWindow *ui;
    avion a;
};

#endif // MAINWINDOW_H


