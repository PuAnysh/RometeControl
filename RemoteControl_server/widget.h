#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtNetwork>
#include <QDebug>
#include <QDesktopWidget>
#include <mytcpserver.h>
#include <server/controler.h>
#include <server/interface.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void onBtnListenClick();
    void ConnectOK();
    void OnConnect();
private:
    QString host;

    //button
    QPushButton* btnlisten;
    QPushButton* btnControl;
    //label
    QLabel* labelstate;
    QLabel* labelCheck;
    QLabel* labelcmd;
    QLabel* labelmap;
    QLabel* labelpasswd;
    QLabel* labelip;
    //edit
    QLineEdit* edtHostIP;
    QLineEdit* edtCheckPort;
    QLineEdit* edtPasswd;
    QLineEdit* edtCmd;
    QLineEdit* edtMap;
    //layout
    QVBoxLayout* mainLayout;
    QHBoxLayout* layoutCheck;
    QHBoxLayout* layoutPasswd;
    QHBoxLayout* layoutcmd;
    QHBoxLayout* layoutmap;
    QHBoxLayout* layoutbtn;
    QHBoxLayout* layoutip;

    //Tcp
    MyTcpServer* tcpserver;

    Controler* control;
};

#endif // WIDGET_H
