#ifndef ALGO_H
#define ALGO_H

#include <QTcpSocket>
#include <iostream>
void writeAndBlock(QTcpSocket* socket, uchar* buf, int len);
void readAndBlock(QTcpSocket* socket, uchar* buf, int len);



#endif // ALGO_H
