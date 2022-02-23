#ifndef ISLEM_H
#define ISLEM_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QDate>
#include <QTime>

class Islem : public QObject
{
    Q_OBJECT
public:
    explicit Islem(QObject *parent = nullptr);
    void veritabaniBaglan();
    QSqlDatabase    db;

private:
    bool veritabaniAc();
    void veritabaniKapat();

signals:
    void girisBasarili(bool a);

public slots:
    void giris();

    bool veriEkle1(const int &deger1, const int &deger2);
    bool veriEkle2(const QVariantList &veriEkle_datam);


};

#endif // ISLEM_H
