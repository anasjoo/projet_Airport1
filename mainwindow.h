#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bagages.h"

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
    void on_Ajouter_clicked();

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

  //  void on_consulter_clicked();

    void on_Bagage_currentChanged(int index);

   // void on_TriBouton_clicked();

    void on_recherche_clicked();

    void on_TriBouton_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
