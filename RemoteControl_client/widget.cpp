#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    //主要布局初始化
    mainLayout = new QHBoxLayout();
    rightlayout = new QVBoxLayout();
    btnlayout = new QHBoxLayout();
    IPlayout = new QHBoxLayout();
    Passwordlayout = new QHBoxLayout();
    CheckPortLayout = new QHBoxLayout();
    ConnectPortLayout = new QHBoxLayout();
    WidLayout = new QHBoxLayout();
    HeiLayout = new QHBoxLayout();
    leftlayout = new QVBoxLayout();
    //主要控件初始化
        //按钮
    btnConnect = new QPushButton("连接" , this);
    btnWork = new QPushButton("控制" , this);
    btnWork->setDisabled(true);
        //QLable控件的初始化
    laip = new QLabel("IP地址  " , this);
    Lapasswd = new QLabel("认证口令" ,  this);
    CheckLable = new QLabel("验证端口" , this);
    ConnectLable = new QLabel("数据端口", this);
    cmdLabel = new QLabel("命令端口" , this);
    WindowsWid = new QLabel("控制窗口宽度", this);
    WindowsHei = new QLabel("控制窗口高度" , this);
    listtable = new QLabel("历史记录" , this);
        //QLineEdit控件的初始化
    GetIP =  new QLineEdit(this);
    GetPasswd = new QLineEdit(this);
    edtCheckPort = new QLineEdit(this);

    edtConnectPort = new QLineEdit(this);
    edtConnectPort->setReadOnly(true);
    edtWid = new QLineEdit(this);
    edtHei = new QLineEdit(this);
    edtcmd = new QLineEdit(this);
    edtcmd->setReadOnly(true);
        //list控件的初始化
    m_hisView = new QListWidget(this);
    m_hisView->setFixedWidth(150);
//    m_hisView->addItem("192.168.1.1");
//    m_hisView->addItem("192.168.1.1");
//    m_hisView->addItem("192.168.1.1");
//    m_hisView->addItem("192.168.1.1");
//    m_hisView->addItem("192.168.1.1");
    //布局设置

    btnlayout->addWidget(btnConnect);
    btnlayout->addWidget(btnWork);
    IPlayout->addWidget(laip);
    IPlayout->addWidget(GetIP);
    Passwordlayout->addWidget(Lapasswd);
    Passwordlayout->addWidget(GetPasswd);
    CheckPortLayout->addWidget(CheckLable);
    CheckPortLayout->addWidget(edtCheckPort);
    ConnectPortLayout->addWidget(ConnectLable);
    ConnectPortLayout->addWidget(edtConnectPort);
    ConnectPortLayout->addWidget(cmdLabel);
    ConnectPortLayout->addWidget(edtcmd);
    WidLayout->addWidget(WindowsWid);
    WidLayout->addWidget(edtWid);
    HeiLayout->addWidget(WindowsHei);
    HeiLayout->addWidget(edtHei);
    //布局开始
    rightlayout->addLayout(IPlayout);
    rightlayout->addLayout(Passwordlayout);
    rightlayout->addLayout(CheckPortLayout);
    rightlayout->addLayout(ConnectPortLayout);
    rightlayout->addLayout(WidLayout);
    rightlayout->addLayout(HeiLayout);
    rightlayout->addLayout(btnlayout);
    leftlayout->addWidget(listtable);
    leftlayout->addWidget(m_hisView);
    mainLayout->addLayout(leftlayout
                          );
    mainLayout->addLayout(rightlayout);
    this->setLayout(mainLayout);
    //信号槽设置
    connect(btnConnect , SIGNAL(clicked(bool)) , this ,SLOT(onConnectClicked()));
    connect(m_hisView , SIGNAL(currentRowChanged(int)) , this ,SLOT(Setinformation(int)) );
    connect(btnWork , SIGNAL(clicked(bool)) , this , SLOT(BeginControl()) );

    //list初始化
    initList(m_hisView);
   // this->setSizePolicy(Qt::MinimumSize);

    t = new QTcpSocket();


    connect(t ,SIGNAL(connected()) , this , SLOT(sent()) );
    connect(t , SIGNAL(readyRead()) , this ,SLOT(READ()));
    ///////////

}

Widget::~Widget()
{

}

void Widget::onConnectClicked()
{
    QString host = GetIP->text();
    QString passwd = GetPasswd->text();
    int tCheckport = edtCheckPort->text().toInt();
    if(host.size() == 0|| passwd.size() == 0 || tCheckport == 0 ) return ;
   // qDebug()<<host<<" "<<passwd<<" "<<tCheckport<<" "<<tmapport<<endl;
    addr = host;
//    qDebug()<<"Connecting"<<endl;
//    t->connectToHost(QHostAddress("127.0.0.1") , 10733);
//    t = new QTcpSocket();
//    t->connectToHost(QHostAddress(host) , tCheckport);
//    connect(t , SIGNAL(connected()) , this , SLOT(BeginControl()) );


    Tcpclient = new TcpPasswd(host , tCheckport ,passwd);
    connect(Tcpclient , SIGNAL(finishread()) , this , SLOT(onTcprecv()));

//        qDebug()<<t->readAll();
//    client.SendMsg(passed.toLatin1());
//    rq_width = edtWid->text().toInt();
//    rq_height = edtHei->text().toInt();
//    ControlWidget* w = new ControlWidget();
//    w->show();
    //    btnWork->setDisabled(false);
}

void Widget::onTcprecv()
{
    QString str = Tcpclient->Recvmsg();
    if(str =="NO") return ;
    QString Width, Height , scmdport , smapport;
    int flag = 0;
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i].isSpace()) {
            flag++;
            continue;
        }
        if(flag == 0) Width.append(str[i]);
        if(flag == 1) Height.append(str[i]);
        if(flag == 2) scmdport.append(str[i]);
        if(flag == 3) smapport.append(str[i]);
    }
    qDebug()<<Width<<Height<<scmdport<<smapport<<endl;
    edtWid->setText(Width);
    edtHei->setText(Height);
    edtcmd->setText(scmdport);
    edtConnectPort->setText(smapport);
    btnWork->setDisabled(false);
    btnConnect->setDisabled(true);


}

void Widget::Setinformation(int index)
{
    ippwd t = vec[vec.size() - index - 1];
    GetIP->setText(t.ip);
    GetPasswd->setText(t.passwd);
    edtCheckPort->setText(t.Checkport);
 //   edtConnectPort->setText(t.Connectport);
}

void Widget::BeginControl()
{
    rq_width = edtWid->text().toInt();
    rq_height = edtHei->text().toInt();
    cmdport = edtcmd->text().toInt();
    mapport= edtConnectPort->text().toInt();
    ControlWidget* w = new ControlWidget();
    w->show();
    connect(w , SIGNAL(close()) , this , SLOT(NewConnect()) );
    btnWork->setDisabled(true);
    QFile data("hislist");
    if(data.open(QFile::Append)){
        QTextStream out(&data);
        out<<tr("Connect")<<endl;
        out<<GetIP->text()<<endl;
        out<<GetPasswd->text()<<endl;
        out<<edtCheckPort->text()<<endl;
    }
    initList(m_hisView);

}

void Widget::NewConnect()
{
    btnConnect->setDisabled(false);
}

void Widget::initList(QListWidget* m_Widget)
{
    m_Widget->clear();
    vec.clear();
    ifstream fin("hislist");
    string str;
    while(fin>>str){
        ippwd t;
        fin>>t.ip>>t.passwd>>t.Checkport;

    //    cout<<t.ip<<" "<<t.passwd<<endl;
        vec.push_back(t);
        //cout<<vec.size()<<endl;
    }

    for(int i = vec.size()-1 ; i >= 0 ; i--){
        //qDebug<<QString(vec[i].ip);
        m_Widget->addItem(QString(vec[i].ip));
        qDebug()<<QString(vec[i].ip)<<endl;
    }
    if(vec.size() > 0) m_Widget->setCurrentRow(0);

}



void Widget::sent()
{
    t->write("sdfdsf");
}

void Widget::READ()
{
    qDebug()<< QString(t->readAll());
}


