#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow_Bagage.h"

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

public:
    Ui::Menu *ui;
private:
    MainWindow anas;
};

#endif // MENU_H
