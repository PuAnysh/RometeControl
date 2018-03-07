#ifndef WIDGET_H
#define WIDGET_H
#include <iostream>
#include <fstream>
#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <tcppasswd.h>
#include <QtNetwork>
#include <QTextStream>
#include <QFile>
#include <vector>
#include <controlwidget.h>
#include <client/values.h>

using namespace std;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    struct ippwd{
        char ip[50];
        char passwd[50];
        char Checkport[50];

    };

public slots:
    void onConnectClicked();
    void onTcprecv();
    void Setinformation(int index);
    void BeginControl();
    void NewConnect();
    void sent();
    void READ();
protected:
    void initList(QListWidget* m_Widget);

private:
    TcpPasswd *Tcpclient;
    QTcpSocket *t;
    vector<ippwd> vec;

    QLabel* laip;
    QLabel* Lapasswd;
    QLabel* CheckLable;
    QLabel* ConnectLable;
    QLabel* WindowsWid;
    QLabel* WindowsHei;
    QLabel* listtable;
    QLabel* cmdLabel;
    QLineEdit* edtWid;
    QLineEdit* edtHei;
    QLineEdit* edtCheckPort;
    QLineEdit* edtConnectPort;
    QLineEdit* GetIP;
    QLineEdit* GetPasswd;
    QLineEdit* edtcmd;
    QListWidget* m_hisView;
    QVBoxLayout* rightlayout;
    QVBoxLayout* leftlayout;
    QHBoxLayout* mainLayout;
    QHBoxLayout* btnlayout;
    QHBoxLayout* IPlayout;
    QHBoxLayout* Passwordlayout;
    QHBoxLayout* CheckPortLayout;
    QHBoxLayout* ConnectPortLayout;
    QHBoxLayout* WidLayout;
    QHBoxLayout* HeiLayout;
    QPushButton* btnConnect;
    QPushButton* btnWork;
};

#endif // WIDGET_H
