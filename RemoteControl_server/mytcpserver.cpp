#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QString host, int port,QString pwd ,  QObject *parent): QObject(parent)
{
    this->host = host;
    this->port = port;
    this->passwd = pwd;
    qDebug()<<passwd<<endl;
    tcpserver = new QTcpServer();
    tcpserver->listen(QHostAddress::Any , port);
    connect(tcpserver, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

 //  connect(tcpserver , SIGNAL(newConnection()) , this , SLOT(readDate()) ) ;
}

void MyTcpServer::acceptConnection()
{
    clientConnection = tcpserver->nextPendingConnection();
    currenthost = clientConnection->peerAddress();
    qDebug()<<currenthost<<endl;
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
    qDebug()<<"client coming"<<endl;
}

void MyTcpServer::readClient()
{
    str = clientConnection->readAll();

    if(str.contains(passwd)){
        QString t = QString("%1 %2 %3 %4").arg(screen_width).arg(screen_height).arg(cmdport).arg(mapport);
        qDebug()<<t;
        clientConnection->write(t.toLatin1());
        emit TcpOK();
    }
    else
    {
        QString tt("NO");
        clientConnection->write(tt.toLatin1());
    }
}
