#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <qdebug.h>
#include <form.h>
#include <QPixmap>
#include "giriss.h"
#include <qdialog.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

   //Dialog penceresi aktif etme.
    Dialog *pencere = new Dialog();
    pencere->show();

        //DATABASE BAĞLANTISI
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setDatabaseName("veritabanim");
        db.setUserName("postgres");
        db.setPassword("172754");

        //Database açık/kapalı kontrol.
        if(!db.open()){
            QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
        }
        /*else{
            QMessageBox::information(this,"DURUM","Veri tabanı bağlandı");
        }*/



           //Tablo oluşturma tableView atama.
            QSqlQuery *query = new QSqlQuery;
            query->exec("SELECT * FROM derece");
            QSqlQueryModel *model_tablom = new QSqlQueryModel;
            model_tablom->setQuery(*query);
            ui->tableView->setModel(model_tablom);



                //EXCEL  işlemleri.
                //Toplam Ürün Sayısı COUNT işlemi.
                QSqlQuery *queryCount = new QSqlQuery;
                queryCount->exec("SELECT count(*) FROM derece");
                queryCount->next();
                int sno_sayisi = queryCount->value(0).toInt();




                //Toplam Ürün Sayısı COUNT işlemi
                while(query->next()){
                     dereceNom_1 << query->value(1).toString();
                     dereceNom << query->value(2).toString();
                     sicaklik_trh << query->value(3).toString();
                     sicaklik_st << query->value(4).toString();
                   //  sicaklik_ort << query->value(5).toString();
                }

//Excele yazdırma.
                QFile dosyam("C:/Users/samar/OneDrive/Masaüstü/excell/excel.csv");
                dosyam.open(QIODevice::WriteOnly);
                QTextStream ciktimiz(&dosyam);

                for (int i=0; i<sno_sayisi; i++ ) {
                    sicaklik_tarih = sicaklik_trh[i];
                    sicaklik_saat = sicaklik_st[i];
                   // sicaklik_ortalama = sicaklik_ort[i];
                    derece_1 = dereceNom_1[i];
                    derece = dereceNom[i];
                    ciktimiz<<derece_1<<";"<< derece<<";"<<sicaklik_tarih<<";"<<sicaklik_saat<<";"<<Qt::endl;
                }
//modbus bağlantısı.

                int mod_sayi1 = ui->seviye_A->value();
                int mod_sayi2 = ui->seviye_B->value();

                 mb_sayim1=QString::number(mod_sayi1);
                 mb_sayim2=QString::number(mod_sayi2);
//tarih zaman tanımladık.
                QDate trh = QDate::currentDate();
                QTime saat = QTime::currentTime();
                QString sicaklik_saat=saat.toString();
                QString trhh = trh.toString(Qt::ISODate);
//veritabanına ekleme.
                QSqlQuery *query_ekle = new QSqlQuery;
                query_ekle->exec("INSERT INTO derece VALUES(DEFAULT,'"+mb_sayim1+"','"+mb_sayim2+"','"+trhh+"','"+sicaklik_saat+"')");
/*

                QCalendarWidget * takvimi;
                takvimi->setGridVisible( true );
                takvimi->setDateRange(1, 2);


                takvimi->setMinimumDate(1);
                ->setMaximumDate(2);

              QCalendarWidget * takvimi;
               takvimi->setGridVisible( true );
              QCalendarWidget::SingleSelection
*/
//Resim eklentileri.
                QPixmap pix("C:/Users/samar/OneDrive/Masaüstü/image/Resim2");
                ui->label_image->setPixmap(pix.scaled(105,100,Qt::KeepAspectRatio));
                QPixmap pix2("C:/Users/samar/OneDrive/Masaüstü/image/Resim2");
                ui->label_image2->setPixmap(pix.scaled(105,100,Qt::KeepAspectRatio));
                //QPixmap pix3("C:/Users/samar/OneDrive/Masaüstü/image/Resim1");
            //   ui->label_image_alt->setPixmap(pix3);

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{





//lcd number ortalamayı gösterme.
//sicaklik_1 ve sicaklik2'nin ortalamasını alma.

    QSqlQuery *qry_ort1 = new QSqlQuery;
    qry_ort1->exec("SELECT AVG(sicaklik_1) FROM derece WHERE sicaklik_tarih>='"+takvimm_1+"' AND sicaklik_tarih<='"+takvimm_2+"'");

//sicaklik_1 float çervirme ve lcdnumber'e atama.
    while(qry_ort1->next())
    {
         sicaklik1_deger = qry_ort1->value(0).toFloat();
       //  qDebug() << sicaklik1_deger;
    }
    ui->lcdNumber->display(sicaklik1_deger);


//sicaklik_2 ortalama alma.
    QSqlQuery *qry_ort2 = new QSqlQuery;
    qry_ort2->exec("SELECT AVG(sicaklik_2) FROM derece WHERE sicaklik_tarih>='"+takvimm_1+"' AND sicaklik_tarih<='"+takvimm_2+"'");

//sicaklik_2 float çervirme ve lcdnumber_2'e atama.
    while(qry_ort2->next())
    {
         sicaklik2_deger = qry_ort2->value(0).toFloat();
       //  qDebug() << sicaklik2_deger;
    }
    ui->lcdNumber_2->display(sicaklik2_deger);

}





//Login işlemi sıgnal slot hata dosya yenile.
/*
    //veritabanı users girişi.
   QSqlQuery *giris = new QSqlQuery;

 QString ad = yeni_pencere->get_new_sicaklik_1();
 QString sifre = yeni_pencere->get_new_sicaklik_2();

    giris->exec("SELECT id FROM login WHERE username='"+ad+"',password='"+sifre+"')");

       if(ad=="2" && sifre=="2"){
            ui->label_3->setText("yes");
*/

/*
 * //Random sayi atama.
void MainWindow::on_pushButton_yenile_clicked()
{

    QDate trh = QDate::currentDate();
    QTime saat = QTime::currentTime();
    QString sicaklik_saat=saat.toString();
    QString trhh = trh.toString(Qt::ISODate);
    QSqlQuery *query_ekle = new QSqlQuery;
    //Random Sayı
   // std::uniform_int_distribution<int> sayiUretici1(20,30);
  //  random_sayi1=sayiUretici1(*QRandomGenerator::global());
   // random_sayi2=sayiUretici1(*QRandomGenerator::global());
  //  random_sayim1=QString::number(random_sayi1);
 //random_sayim2=QString::number(random_sayi2);
    //qDebug()<< random_sayim1;
  //  qDebug()<< random_sayim2;
   // qDebug()<< trhh;
   // qDebug()<< sicaklik_saat;
   // qDebug()<<query_ekle;


    query_ekle->exec("INSERT INTO derece VALUES(DEFAULT, '"+random_sayim1+"','"+random_sayim2+"','"+trhh+"','"+sicaklik_saat+"')");

    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM derece");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*query);
    ui->tableView->setModel(model_tablom);



}
*/


//Takvim filtreleme
void MainWindow::on_pushButton_takvim_aralk_clicked()
{

      QDate takvim_1 = ui->calendarWidget_1->selectedDate();
      takvimm_1 = takvim_1.toString(Qt::ISODate);

      QDate takvim_2 =ui->calendarWidget_2->selectedDate();
      takvimm_2 = takvim_2.toString(Qt::ISODate);

      //qDebug() << takvimm_1;
      //qDebug() << takvimm_2;

      QSqlQuery *qry_listele1 = new QSqlQuery;
      qry_listele1->exec("SELECT * FROM derece WHERE sicaklik_tarih>='"+takvimm_1+"' AND sicaklik_tarih<='"+takvimm_2+"'  ORDER BY sicaklik_id DESC ");
      QSqlQueryModel *model_takvim = new QSqlQueryModel;
      model_takvim->setQuery(*qry_listele1);
      ui->tableView->setModel(model_takvim);



}


