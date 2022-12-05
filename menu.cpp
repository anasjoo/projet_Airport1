#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "passager.h"

#include "avions.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_gestionBagage_clicked()
{
    anas.show();

}

void Menu::on_logout_clicked()
{
  hide();
}

void Menu::on_gestionPasager_clicked()
{
    yosr.show();
}

void Menu::on_gestionVol_clicked()
{
    nessrin.show();

}

void Menu::on_gestionEmployee_clicked()
{
    aziz.show();
}

void Menu::on_gestionBillet_clicked()
{
    ayoub.show() ;
}

void Menu::on_gestionAvion_clicked()
{
    Avions *av= new Avions();
    av->show();
}
