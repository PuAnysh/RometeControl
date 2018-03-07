#include "tcppasswd.h"

TcpPasswd::TcpPasswd(QString hostname , int port , QString str , QObject* parent ) : QObject(parent)
{
    client = new QTcpSocket();
    host = hostname;
    this->port = port;
    this->str = str;
    qDebug()<<host<<" "<<port<<" "<<str<<endl;
    client->connectToHost(QHostAddress(host) , port);
    //client->waitForConnected(3000);
    //client->connectToHost("127.0.0.1" , 10933);
    connect(client , SIGNAL(readyRead()) , this , SLOT(readRecvmsg()) ) ;
    connect(client , SIGNAL(connected())  , this ,SLOT(Succeed()));
    qDebug()<<"Tcp init";
}

QString TcpPasswd::Recvmsg()
{
    return QString(recvmsg);
}

void TcpPasswd::readRecvmsg()
{
    recvmsg = client->readAll();
    emit finishread();
    qDebug()<<QString(recvmsg)<<endl;
}

void TcpPasswd::Succeed()
{

    client->write(str.toLatin1());
    qDebug()<<str<<endl;
}

void TcpPasswd::Unsucceed()
{

}
