#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QtNetwork>
#include <server/interface.h>
#include <value.h>
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    MyTcpServer(QString host , int port  ,QString pwd ,  QObject *parent = 0);

signals:
    void TcpOK();
public slots:
 //   void readDate();
    void acceptConnection();
    void readClient();
private:
    QTcpServer* tcpserver;
    QTcpSocket *clientConnection;
    QString host;
    QString passwd;
    QString str;
    int port;
};

#endif // MYTCPSERVER_H
