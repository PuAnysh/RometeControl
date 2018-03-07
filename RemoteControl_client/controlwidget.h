#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QRect>
#include <QTcpSocket>
#include <QHostAddress>
#include <QImage>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <client/values.h>
#include "client/mapthread.h"
#include "client/cmdthread.h"
#include "client/controlpanel.h"
class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlWidget(QWidget *parent = 0);

signals:
    void keyPressed(QKeyEvent *);
    void keyReleased(QKeyEvent *);
    void close();

public slots:
protected:
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    ControlPanel* controlPanel;
    QHBoxLayout* layout;

};

#endif // CONTROLWIDGET_H
