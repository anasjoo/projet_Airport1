#ifndef VOL_H
#define VOL_H
# include <QString>
#include <QSqlQueryModel>

class Vol
{
public:
    Vol();
    Vol (int, QString,QString);
    int getID_VOL();
    QString getDIRECTION();
    QString getDATE_VOL();
    void setID_VOL(int);
    void setDIRECTION(QString);
    void setDATE_VOL(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
int ID_VOL ;
QString DATE_VOL, DIRECTION;
};

#endif // VOL_H
