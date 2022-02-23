
#include "mainwindow.h"
#include "comenginea.h"
#include <QThread>
#include <QGuiApplication>
#include <qdebug.h>
#include <QApplication>
#include "giriss.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.show();
    ComEngineA driverA(&a);
    bool debugSta=true;



QObject* seviye_A = w.findChild<QObject*>("seviye_A");
QObject::connect(&driverA, &ComEngineA::HoldingRegisters0, [=](int value){ seviye_A->setProperty("value", value/10);if(debugSta){qDebug() <<seviye_A<<value;}});

QObject* seviye_B = w.findChild<QObject*>("seviye_B");
QObject::connect(&driverA, &ComEngineA::HoldingRegisters1, [=](int value){ seviye_B->setProperty("value", value/10);if(debugSta){qDebug() <<seviye_B<<value;}});


giriss g;
g.show();

    return a.exec();
}
