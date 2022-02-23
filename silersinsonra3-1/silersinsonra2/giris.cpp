#include "giris.h"
#include "ui_giris.h"
#include <QMessageBox>
#include <QPixmap>

Giris::Giris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Giris)
{
    ui->setupUi(this);

    //Resim eklentisi.
   QPixmap pix4("C:/Users/samar/OneDrive/Masaüstü/image/login");
   ui->label_login->setPixmap(pix4);
}

Giris::~Giris()
{
    delete ui;
}

void Giris::on_pushButton_giris_clicked()
{


}
