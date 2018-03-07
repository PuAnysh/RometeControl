#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //初始化参数


    QString t = QString("%1 %2").arg(screen_width).arg(screen_height);
    qDebug()<<t;


    //获得本机IP地址
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    foreach(QHostAddress address,info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol) {
             qDebug() << address.toString();
             host = address.toString();
         }

    }


    //PushButton初始化
    btnlisten = new QPushButton("允许连接" , this);
    btnControl = new QPushButton("断开控制" ,this);
    btnControl->setDisabled(true);
    //QLabel初始化


    labelstate = new QLabel("Unconnect" , this);
    labelip = new QLabel("本机 IP" , this);
    labelCheck = new QLabel("认证端口" , this);
    labelcmd = new QLabel("控制端口",this);
    labelmap = new QLabel("数据端口" ,this);
    labelpasswd = new QLabel("认证口令",this);

    //edit初始化
    edtHostIP = new QLineEdit(this);
    edtHostIP->setText(host);
    edtHostIP->setReadOnly(true);
    edtCheckPort = new QLineEdit(this);
    edtPasswd = new QLineEdit(this);
    edtCmd = new QLineEdit(this);
//    edtCmd->setReadOnly(true);
    edtMap = new QLineEdit(this);
//    edtMap->setReadOnly(true);
    //Layout初始化
    mainLayout = new QVBoxLayout();
    layoutCheck = new QHBoxLayout();
    layoutcmd = new QHBoxLayout();
    layoutmap = new QHBoxLayout();
    layoutPasswd = new QHBoxLayout();
    layoutbtn = new QHBoxLayout();
    layoutip = new QHBoxLayout();
    //布局
    layoutbtn->addWidget(btnlisten);
    layoutbtn->addWidget(btnControl);

    layoutip->addWidget(labelip);
    layoutip->addWidget(edtHostIP);

    layoutCheck->addWidget(labelCheck);
    layoutCheck->addWidget(edtCheckPort);

    layoutPasswd->addWidget(labelpasswd);
    layoutPasswd->addWidget(edtPasswd);

    layoutcmd->addWidget(labelcmd);
    layoutcmd->addWidget(edtCmd);

    layoutmap->addWidget(labelmap);
    layoutmap->addWidget(edtMap);

    mainLayout->addWidget(labelstate);
    mainLayout->addLayout(layoutip);
    mainLayout->addLayout(layoutCheck);
    mainLayout->addLayout(layoutPasswd);
    mainLayout->addLayout(layoutcmd);
    mainLayout->addLayout(layoutmap);
    mainLayout->addLayout(layoutbtn);
    this->setLayout(mainLayout);

    connect(btnlisten , SIGNAL(clicked(bool)) , this ,SLOT(onBtnListenClick()) ) ;
    connect(btnControl , SIGNAL(clicked(bool)) , this ,SLOT(OnConnect()) );
}

Widget::~Widget()
{

}

void Widget::onBtnListenClick()
{
    //MyTcpServer(QString host , int port  ,QString pwd ,  QObject *parent = 0);
    int port = edtCheckPort->text().toInt();
    QString ps = edtPasswd->text();
    tcpserver = new MyTcpServer(host , port , ps);
    connect(tcpserver , SIGNAL(TcpOK()) , this , SLOT(ConnectOK()) );
    cmdport = edtCmd->text().toInt();
    mapport = edtMap->text().toInt();
    btnlisten->setDisabled(true);
}

void Widget::ConnectOK()
{
    qDebug()<<"Tcp CONNECT CREATE"<<endl;
    btnControl->setDisabled(false);
    control = new Controler();
    qDebug()<<"Begin be control"<<endl;
}

void Widget::OnConnect()
{
    delete control;
    btnControl->setDisabled(true);
    btnlisten->setDisabled(false);
}
