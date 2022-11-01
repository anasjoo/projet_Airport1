#ifndef VOL_H
#define VOL_H
# include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class Vol
{
public:
    Vol();
    Vol (int, QString,QString,QString);
    int getID_VOL();
    QString getDIRECTION();
    QString getARRIVE_VOL();
    QString getDEPART_VOL();
    void setID_VOL(int);
    void setDIRECTION(QString);
    void setARRIVE_VOL(QString);
    void setDEPART_VOL(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
private:
int ID_VOL ;
QString ARRIVE_VOL,DEPART_VOL, DIRECTION;
};

#endif // VOL_H
