#include "tcpclient.h"

Tcpclient::Tcpclient(QString hostname , int port ,QString str , QObject *parent) : QObject(parent)
{
    client = new QTcpSocket();
    host = hostname;
    this->port = port;
    this->str = str;
    qDebug()<<host<<" "<<port<<" "<<str<<endl;
    //client->connectToHost(QHostAddress(host) , port);
    //client->connectToHost("127.0.0.1" , 10933);
    connect(client , SIGNAL(readyRead()) , this , SLOT(readRecvmsg()) ) ;
    connect(client , SIGNAL(connected())  , this ,SLOT(Succeed()));
    qDebug()<<"Tcp init";
}

QString Tcpclient::Recvmsg()
{
    return QString(recvmsg);
}

void Tcpclient::readRecvmsg()
{
    recvmsg = client->readAll();
    emit finishread();
    qDebug()<<QString(recvmsg)<<endl;
}

void Tcpclient::Succeed()
{

    client->write(str.toLatin1());
    qDebug()<<str<<endl;
}
