/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ID;
    QLineEdit *le_NUMS;
    QLineEdit *le_NUMV;
    QPushButton *button_ajouter;
    QWidget *tab_2;
    QTableView *tabE;
    QPushButton *pushButton;
    QPushButton *recher;
    QLineEdit *line;
    QComboBox *comboBox;
    QLabel *label_6;
    QPushButton *trier;
    QWidget *widget;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *up_ID;
    QLineEdit *up_NUMS;
    QLineEdit *up_NUMV;
    QPushButton *updateBP;
    QWidget *tab_3;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QPushButton *pbSupprimer;
    QLabel *label_5;
    QLineEdit *le_IDsup;
    QWidget *tab_4;
    QGroupBox *groupBox_4;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QLineEdit *file;
    QLineEdit *msg;
    QPushButton *browseBtn;
    QPushButton *sendBtn;
    QLineEdit *mail_pass;
    QGroupBox *groupBox_5;
    QPushButton *pb_code;
    QLabel *label_qrcode;
    QGroupBox *groupBox_6;
    QPushButton *pb_excel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(890, 554);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 30, 811, 441));
        tabWidget->setStyleSheet(QLatin1String("font: italic 8pt \"Comic Sans MS\";\n"
"background-color: rgb(85, 170, 255);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(110, 60, 501, 241));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 47, 14));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 61, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 81, 16));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(80, 30, 111, 20));
        lineEdit_ID->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_ID->setMaxLength(99999999);
        le_NUMS = new QLineEdit(groupBox);
        le_NUMS->setObjectName(QStringLiteral("le_NUMS"));
        le_NUMS->setGeometry(QRect(80, 60, 113, 20));
        le_NUMS->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_NUMS->setMaxLength(999999);
        le_NUMV = new QLineEdit(groupBox);
        le_NUMV->setObjectName(QStringLiteral("le_NUMV"));
        le_NUMV->setGeometry(QRect(100, 90, 113, 20));
        le_NUMV->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_NUMV->setMaxLength(9999);
        button_ajouter = new QPushButton(groupBox);
        button_ajouter->setObjectName(QStringLiteral("button_ajouter"));
        button_ajouter->setGeometry(QRect(290, 120, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabE = new QTableView(tab_2);
        tabE->setObjectName(QStringLiteral("tabE"));
        tabE->setGeometry(QRect(20, 30, 421, 241));
        tabE->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 290, 93, 28));
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 127);\n"
"background-color: rgb(255, 0, 127);"));
        recher = new QPushButton(tab_2);
        recher->setObjectName(QStringLiteral("recher"));
        recher->setGeometry(QRect(590, 70, 93, 28));
        line = new QLineEdit(tab_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(520, 40, 113, 22));
        line->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 280, 41, 22));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(161, 240, 255);"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 280, 71, 16));
        trier = new QPushButton(tab_2);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(70, 320, 81, 28));
        tabWidget->addTab(tab_2, QString());
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 100, 411, 171));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 30, 47, 14));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 60, 71, 20));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 90, 71, 20));
        up_ID = new QLineEdit(groupBox_2);
        up_ID->setObjectName(QStringLiteral("up_ID"));
        up_ID->setGeometry(QRect(80, 30, 113, 21));
        up_ID->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        up_NUMS = new QLineEdit(groupBox_2);
        up_NUMS->setObjectName(QStringLiteral("up_NUMS"));
        up_NUMS->setGeometry(QRect(80, 60, 113, 21));
        up_NUMS->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        up_NUMV = new QLineEdit(groupBox_2);
        up_NUMV->setObjectName(QStringLiteral("up_NUMV"));
        up_NUMV->setGeometry(QRect(80, 90, 113, 21));
        up_NUMV->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        updateBP = new QPushButton(groupBox_2);
        updateBP->setObjectName(QStringLiteral("updateBP"));
        updateBP->setGeometry(QRect(230, 130, 80, 22));
        tabWidget->addTab(widget, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 40, 47, 14));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(130, 60, 351, 161));
        pbSupprimer = new QPushButton(groupBox_3);
        pbSupprimer->setObjectName(QStringLiteral("pbSupprimer"));
        pbSupprimer->setGeometry(QRect(240, 100, 75, 23));
        pbSupprimer->setStyleSheet(QLatin1String("font: 63 8pt \"Yu Gothic UI Semibold\";\n"
"color: rgb(2, 103, 115);"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 61, 16));
        le_IDsup = new QLineEdit(groupBox_3);
        le_IDsup->setObjectName(QStringLiteral("le_IDsup"));
        le_IDsup->setGeometry(QRect(100, 50, 113, 20));
        le_IDsup->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 0, 611, 391));
        rcpt = new QLineEdit(groupBox_4);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(50, 80, 401, 22));
        rcpt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        subject = new QLineEdit(groupBox_4);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(50, 120, 401, 22));
        subject->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        file = new QLineEdit(groupBox_4);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(50, 170, 401, 22));
        file->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        msg = new QLineEdit(groupBox_4);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(60, 210, 401, 151));
        msg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        browseBtn = new QPushButton(groupBox_4);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(470, 170, 93, 28));
        sendBtn = new QPushButton(groupBox_4);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(480, 350, 93, 28));
        mail_pass = new QLineEdit(groupBox_4);
        mail_pass->setObjectName(QStringLiteral("mail_pass"));
        mail_pass->setGeometry(QRect(460, 80, 131, 22));
        mail_pass->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        mail_pass->setDragEnabled(false);
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(650, 179, 141, 171));
        pb_code = new QPushButton(groupBox_5);
        pb_code->setObjectName(QStringLiteral("pb_code"));
        pb_code->setGeometry(QRect(10, 30, 93, 28));
        label_qrcode = new QLabel(groupBox_5);
        label_qrcode->setObjectName(QStringLiteral("label_qrcode"));
        label_qrcode->setGeometry(QRect(25, 90, 91, 101));
        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(640, 60, 120, 80));
        pb_excel = new QPushButton(groupBox_6);
        pb_excel->setObjectName(QStringLiteral("pb_excel"));
        pb_excel->setGeometry(QRect(20, 30, 93, 28));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 890, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "NUM VOL", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "NUM SIEGE", Q_NULLPTR));
        button_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ajouter service", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        recher->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Trier par ", Q_NULLPTR));
        trier->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "consulter la liste", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "update", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "NUM VOL ", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "NUM SIEGE", Q_NULLPTR));
        updateBP->setText(QApplication::translate("MainWindow", "update", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("MainWindow", "update", Q_NULLPTR));
        label_4->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Suppression", Q_NULLPTR));
        pbSupprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "supprimer service", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("MainWindow", "parcourir", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("MainWindow", "envoyer", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Qr Code", Q_NULLPTR));
        pb_code->setText(QApplication::translate("MainWindow", "Qrcode", Q_NULLPTR));
        label_qrcode->setText(QString());
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Excel case ", Q_NULLPTR));
        pb_excel->setText(QApplication::translate("MainWindow", "excel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "mail", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
