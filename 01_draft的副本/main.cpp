#include "mywidget.h"

#include <QApplication>     //包含一个应用程序类的头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   //a为应用程序对象 有且仅有一个
    myWidget w;    //窗口对象 myWidget父类->QWidget
    w.show();      //窗口对象用show显示
    return a.exec();   //让应用程序对象进入消息循环 让代码阻塞在该行
}
