#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork>

class Tcpclient : public QObject
{
    Q_OBJECT
public:
    explicit Tcpclient(QString hostname , int port ,QString str , QObject *parent = 0);
    QString Recvmsg();
signals:
    void finishread();
public slots:
    void readRecvmsg();
    void Succeed();
private:
    int port;

    QString host;
    QString str;
    QTcpSocket *client;
    QByteArray recvmsg;
};

#endif // TCPCLIENT_H
