#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>



class Employee
{
public:
    Employee();
    Employee(int,QString,QString,QString);

        QString getnom();
        QString getprenom();
        QString getfonction();
        int getid();

        void setnom (QString);
        void setprenom (QString);
        void setfonction (QString);
        void setid(int);
        bool ajouter();
        QSqlQueryModel *afficher();
        bool supprimer (int id);
        bool modifier();
        QSqlQueryModel * tri();
        QSqlQueryModel * tri1();
        QSqlQueryModel * tri2();
        QSqlQuery request(QString);

private:
        QString nom , prenom, fonction ;
         int  id  ;
};

#endif // EMPLOYEE_H
