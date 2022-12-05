#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QDialog>
#include"employee.h"
#include <QMainWindow>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class employer;
}
QT_END_NAMESPACE
class employer : public QDialog
{
    Q_OBJECT

public:
    explicit employer(QWidget *parent = nullptr);
    ~employer();
private slots:
    void update_label();

    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();

    void on_tri_prenom_clicked();

    void on_rechPB_clicked();

    void on_tab_empl_clicked(const QModelIndex &index);

    void on_convertir_clicked();

    void on_pb_stat_clicked();

    //void on_idLogin_cursorPositionChanged(int arg1, int arg2);

    void on_retourner_clicked();

private:
    Ui::employer *ui;
    Employee E;
    Arduino A ;
    QByteArray data; // variable contenant les données reçues

             QString c="";
             int t=0;

};

#endif // EMPLOYER_H

