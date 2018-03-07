#include "widget.h"
#include <QApplication>
#include <server/interface.h>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget* deskWidget = a.desktop();
    QRect screenRect  = deskWidget->screenGeometry();
    screen_width = screenRect.width();
    screen_height = screenRect.height();
    Widget w;
    w.show();

    return a.exec();
}

//#include <QApplication>
//#include <QDesktopWidget>

//#include "server/interface.h"
//#include "server/controler.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QDesktopWidget* deskWidget = a.desktop();
//    QRect screenRect  = deskWidget->screenGeometry();
//    screen_width = screenRect.width();
//    screen_height = screenRect.height();

//    new Controler;
//    //MainWindow w;
//    //w.show();

//    return a.exec();
//}
