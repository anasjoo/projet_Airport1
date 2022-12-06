#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow_Bagage.h"
#include "passager.h"
#include "vol.h"
#include "gestion_vol.h"
#include "employer.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_gestionBagage_clicked();

    void on_logout_clicked();

    void on_gestionPasager_clicked();

    void on_gestionVol_clicked();

    void on_gestionEmployee_clicked();

public:
    Ui::Menu *ui;
private:
    MainWindow anas;
    Passager yosr;
    Vol nessrin;
    employer aziz ;

};

#endif // MENU_H
