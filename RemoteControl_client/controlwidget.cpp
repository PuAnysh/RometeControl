#include "controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout;
    controlPanel = new ControlPanel(QRect(0, 0, rq_width, rq_height), this);
    layout->addWidget(controlPanel);
    this->setFixedSize(rq_width ,rq_height+50);
    connect(this, SIGNAL(keyPressed(QKeyEvent*)), controlPanel, SLOT(keyPressSlot(QKeyEvent*)));
    connect(this, SIGNAL(keyReleased(QKeyEvent*)), controlPanel, SLOT(keyReleaseSlot(QKeyEvent*)));
    this->setLayout(layout);
}

void ControlWidget::closeEvent(QCloseEvent *event)
{
    emit close();
}


void ControlWidget::keyPressEvent(QKeyEvent *e)
{
    emit keyPressed(e);
}

void ControlWidget::keyReleaseEvent(QKeyEvent *e)
{
    emit keyReleased(e);
}
