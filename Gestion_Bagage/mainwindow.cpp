#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bagages.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Ajouter_clicked()
{
     Bagages b;
     b.ajouter(ui);
}

void MainWindow::on_Modifier_clicked()
{
     Bagages b;
     b.Modifier(ui);
}
void MainWindow::on_Supprimer_clicked()
{
     Bagages b;
     b.supprimer(ui);
}

void MainWindow::on_consulter_clicked()
{
    Bagages b;
    b.AfficherTable(ui);
}
