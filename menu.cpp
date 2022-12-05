#include "menu.h"
#include "ui_menu.h"
#include "login.h"


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
    Login l ;
    l.show();
}
