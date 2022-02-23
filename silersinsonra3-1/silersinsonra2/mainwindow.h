#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QDate>
#include <QTime>
#include <QtMath>
#include <QObject>
#include <QTimer>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QVariant>
#include <QModbusTcpClient>
#include "dialog.h"
#include "giris.h"
#include <QRandomGenerator64>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString derece_1;
    QString derece;
    QString  sicaklik_tarih;
    QString  sicaklik_saat;

  //QString  sicaklik_ortalama;

    int sicak1;
    int sicak2;
    QList<QString> dereceNom_1;
    QList<QString> dereceNom;
    QList<QString> sicaklik_trh;
    QList<QString> sicaklik_st;
 // QList<QString> sicaklik_ort;

    float sicaklik1_deger;
    float sicaklik2_deger;


    //Random sayı-modbus gelen sayi.
   QString mb_sayim1;
   QString mb_sayim2;


   QString takvimm_1;
   QString takvimm_2;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_takvim_aralk_clicked();


private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
