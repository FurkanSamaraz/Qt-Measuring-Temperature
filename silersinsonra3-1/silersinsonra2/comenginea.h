#ifndef COMENGINEA_H
#define COMENGINEA_H
#include <QObject>
#include <QTimer>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QVariant>
#include <QModbusTcpClient>

class ComEngineA : public QObject
{
    Q_OBJECT
    volatile bool m_stop;
    QTimer* m_timer;
    QTimer* m_timerRty;
  //  QModbusRtuSerialMaster* m_modbus;
    QModbusClient* m_modbus;


public:
    explicit ComEngineA(QObject *parent = 0);
    ~ComEngineA();
    int x;
    int y;


signals:
    void	DiscreteInputs0     (bool value);
    void	Coils0	(bool value);
    void	InputRegisters0     (int value);
    void	HoldingRegisters0	(int value);

       void	HoldingRegisters1	(int value);

public slots:
    void run();
    void processReadDiscreteInputs();
    void processReadCoils();
    void processReadInputRegisters();
    void processReadHoldingRegisters();
    void processWrite();

   // void	Wr_HoldingRegisters0	(int value);


};

#endif // COMENGINEA_H
