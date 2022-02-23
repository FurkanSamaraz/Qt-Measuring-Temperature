#ifndef GIRISS_H
#define GIRISS_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class giriss;
}

class giriss : public QWidget
{
    Q_OBJECT

public:
    explicit giriss(QWidget *parent = nullptr);
    ~giriss();

private slots:
    void on_pushButton_giris_clicked();

private:
    Ui::giriss *ui;
};

#endif // GIRISS_H
