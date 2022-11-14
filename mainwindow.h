void on_sendsms_clicked();
void on_camera_clicked();
void on_camera_currentChanged(int index);
void on_Bagage_tabBarClicked(int index);
void on_camera_currentChanged(int index);
void on_takeImageButton_clicked();
void on_pdf_clicked();
void on_pushButton_clicked();
void on_pushButton_clicked();
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bagages.h"
#include "smtp.h"
#include <QDebug>
#include <QDialog>
#include "camera.h"

namespace Ui {
class MainWindow;void on_stat_clicked();

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

    void on_Bagage_currentChanged(int index);

    void on_recherche_clicked();

    void on_TriBouton_clicked();

    void on_pdfbouton_clicked();

    void makePlot_type ();
    QVector<double> Statistique_type();
    void on_stat_clicked();

    void on_poids_2_textChanged(const QString &arg1);
    //void on_camera_currentChanged(int index);
    void on_camera_clicked();void on_imprimer_clicked();
    void on_tel_clicked();
void on_sendsms_clicked();



private:
    Ui::MainWindow *ui;
    QStringList files;
    QString mail_pass="QoranKarim123*";

    camera *c;

};

#endif // MAINWINDOW_H
