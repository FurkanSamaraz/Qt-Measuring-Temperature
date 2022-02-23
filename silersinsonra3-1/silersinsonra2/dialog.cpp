#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QPixmap>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


            //Resim eklentisi.
           QPixmap pix("C:/Users/samar/OneDrive/Masaüstü/image/qttt");
           ui->label->setPixmap(pix.scaled(880,900,Qt::KeepAspectRatio));
  }


Dialog::~Dialog()
{
    delete ui;
}
