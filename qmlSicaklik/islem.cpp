#include "islem.h"

Islem::Islem(QObject *parent) : QObject(parent)
{

}

void Islem::veritabaniBaglan()
{
        this->veritabaniAc();
}

bool Islem::veritabaniAc()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sicaklik");
    db.setUserName("postgres");
    db.setPassword("172754");
    if(db.open()){
        qDebug() << "Veri Tabanı Bağlantısı Başarılı";
        return true;
    } else {
        return false;
    }

}

void Islem::veritabaniKapat()
{
    db.close();
}


void Islem::giris()
{
    qDebug() << "Çalıştı";
    girisBasarili(true);
}

bool Islem::veriEkle1(const int &deger1, const int &deger2)
{
    QVariantList veriEkle_datam;
    veriEkle_datam.append(deger1);
    veriEkle_datam.append(deger2);
    if(veriEkle2(veriEkle_datam))
        return true;
    else
        return false;
}

bool Islem::veriEkle2(const QVariantList &veriEkle_datam)
{
    QDate tarih = QDate::currentDate();
    QTime saat = QTime::currentTime();
    QString tarihh = tarih.toString(Qt::ISODate);
    QString saatt = saat.toString();
    //O anki Tarih

    QString sicaklik1= veriEkle_datam[0].toString();
    QString sicaklik2= veriEkle_datam[1].toString();

    QSqlQuery qry_sicaklikEkle;
    qry_sicaklikEkle.exec("INSERT INTO sicakliklar VALUES(DEFAULT,'"+sicaklik1+"','"+sicaklik2+"','"+tarihh+"','"+saatt+"')");
    return true;

}



