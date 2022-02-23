#include "giriss.h"
#include "ui_giriss.h"
#include "mainwindow.h"
#include <QNetworkInterface>
#include <QHostInfo>
giriss::giriss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giriss)
{
    ui->setupUi(this);

    //Resim eklentisi.
   QPixmap pix4("C:/Users/samar/OneDrive/Masaüstü/image/login");
   ui->label_login->setPixmap(pix4);








}

giriss::~giriss()
{
    delete ui;
}

void giriss::on_pushButton_giris_clicked()
{
//GİRİŞ YAPILAN BİLGİSAYARIN MAC ADDRESİNİ ALMA.
    QHostInfo info;
    QString address;
     auto interfaces = QNetworkInterface::allInterfaces();

     for (int i = 0; i < interfaces.length(); i++) {
         if (interfaces[i].isValid()) {
             address = interfaces[i].hardwareAddress();
             break;
         }
     }

     if (address.isEmpty()) {
         qWarning("Yerel donanım adresi edinimi başarısız oldu!");


     }

//LOGİN İÇİN VERİ TABANIN'DAN VERİ ÇEKME.
    QString tempKullanici,tempSifre,macc,tempMac;

    tempKullanici = ui->lineEdit_kullanici->text();
    tempSifre = ui->lineEdit_sifre->text();

    QSqlQuery quer;
    quer.exec("SELECT sifre FROM login WHERE isim='"+tempKullanici+"'");
    quer.first();

   // qDebug()<<quer.value(0).toString()<<tempSifre<<(tempSifre==quer.value(0).toString());

    QSqlQuery *mac =new QSqlQuery;
    mac->exec("SELECT * FROM login");
    mac->first();
   tempMac = mac->value(3).toString();


//LOGİN İŞLEMİNDE SİFRE,KULLANİCİADİ VE MAC ADDRESİ KONTROLÜ.

if(tempSifre==""){
    QMessageBox::critical(this,"Uyarı","Boş girilemez!");
}else{
    if(tempSifre==quer.value(0).toString() && address==tempMac){
        MainWindow *m = new MainWindow;
        m->show();
        this->hide();
}else {

        QMessageBox::warning(0,"uyari","giris olunamadi.");
}
    }
}
