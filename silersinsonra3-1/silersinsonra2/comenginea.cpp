#include "comenginea.h"
#include <QVariant>
#include <QThread>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include "mainwindow.h"

ComEngineA::ComEngineA(QObject *parent)   : QObject(parent)



  , m_timer(new QTimer(this))
   ,m_timerRty(new QTimer(this))
  ,m_modbus(new QModbusTcpClient(this))
{
           m_modbus->setConnectionParameter(QModbusDevice::NetworkPortParameter, 502 );
           m_modbus->setConnectionParameter(QModbusDevice::NetworkAddressParameter, "127.0.0.1" );
           m_modbus->setTimeout(2000);
           m_modbus->setNumberOfRetries(10);


           if (!m_modbus->connectDevice())
           {
               qDebug() << "connectDevice: " << m_modbus->errorString();

           }

           m_timer->setInterval(5000);
           m_timerRty->setInterval(5000);
           connect(m_timer, SIGNAL(timeout()), this, SLOT(run()));
           m_timer->start();

}
ComEngineA::~ComEngineA()
{
    //m_modbus->disconnectDevice();
    //delete m_modbus;
    //delete m_timer;
}


void ComEngineA::run()
{

   //Read Discreate inputs
   //*********************************************************************************//
   QModbusDataUnit readDiscreteInputs(QModbusDataUnit::DiscreteInputs,0,1);
   //  QModbusDataUnit readBool(QModbusDataUnit::Coils,0,99);
    if (auto* reply = m_modbus->sendReadRequest(readDiscreteInputs, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, SIGNAL(finished()), this, SLOT(processReadDiscreteInputs()));
        }
        else
        {
            delete reply;
        }
    }

   //Read Coils
   //*********************************************************************************//
   QModbusDataUnit readCoils(QModbusDataUnit::Coils,0,1);
      if (auto* reply = m_modbus->sendReadRequest(readCoils, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, SIGNAL(finished()), this, SLOT(processReadCoils()));
        }
        else
        {
            delete reply;
        }
    }


    //ReadInputRegisters
    //*********************************************************************************//
  QModbusDataUnit readInputRegisters(QModbusDataUnit::InputRegisters,0,1);
    if (auto* reply = m_modbus->sendReadRequest(readInputRegisters, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, SIGNAL(finished()), this, SLOT(processReadInputRegisters()));
        }
        else
        {
            delete reply;
        }
    }

    //ReadHoldingRegisters
    //*********************************************************************************//
  QModbusDataUnit readHoldingRegisters(QModbusDataUnit::HoldingRegisters, 0,2);
    if (auto* reply = m_modbus->sendReadRequest(readHoldingRegisters, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, SIGNAL(finished()), this, SLOT(processReadHoldingRegisters()));
        }
        else
        {
            delete reply;
        }
    }

}

//*********************************************************************************//
//
//Emiting Registers
//
//*********************************************************************************//


//Read Discreate inputs
//*********************************************************************************//
void ComEngineA::processReadDiscreteInputs()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (reply->error() != QModbusDevice::NoError)
    {
        qDebug() << "sendReadRequest: " << reply->errorString();
    }
    else
    {
        auto result = reply->result();
        emit    DiscreteInputs0     (result.value(0));
    }

    delete reply;
}

//Read Coils
//*********************************************************************************//
void ComEngineA::processReadCoils()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (reply->error() != QModbusDevice::NoError)
    {
        qDebug() << "sendReadRequest: " << reply->errorString();
    }
    else
    {
        auto result = reply->result();
        emit	Coils0	(result.value(0));
    }

    delete reply;
}

//ReadInputRegisters
//*********************************************************************************//
void ComEngineA::processReadInputRegisters()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (reply->error() != QModbusDevice::NoError)
    {
        qDebug() << "sendReadRequest: " << reply->errorString();
    }
    else
    {
        auto result = reply->result();
        emit	InputRegisters0     (result.value(0));

     }

    delete reply;
}

//ReadHoldingRegisters
//*********************************************************************************//
void ComEngineA::processReadHoldingRegisters()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (reply->error() != QModbusDevice::NoError)
    {
        qDebug() << "sendReadRequest: " << reply->errorString();
    }
    else
    {
        auto result = reply->result();
        emit	HoldingRegisters0	(result.value(0));
         emit	HoldingRegisters1	(result.value(1));

     }

    delete reply;
}

void ComEngineA::processWrite()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (reply->error() != QModbusDevice::NoError)
    {
        qDebug() << "sendWriteRequest: " << reply->errorString();
    }

    delete reply;
}
