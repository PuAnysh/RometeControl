#ifndef TCPPASSWD_H
#define TCPPASSWD_H
#include <QObject>
#include <QtNetwork>


class TcpPasswd : public QObject
{
    Q_OBJECT
public:
    TcpPasswd(QString hostname , int port ,QString str , QObject* parent = 0);
    QString Recvmsg();
signals:
    void finishread();
public slots:
    void readRecvmsg();
    void Succeed();
    void Unsucceed();
private:
    int port;

    QString host;
    QString str;
    QTcpSocket *client;
    QByteArray recvmsg;
};

#endif // TCPPASSWD_H
