#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->setText("第一个按钮");

    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    btn2->move(100,100);
    resize(600,400);
    setFixedSize(600,400);
    btn2->resize(50,50);
    setWindowTitle("第一个窗口");

    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(200,0);
    myBtn->setParent(this);

    //需求 点击我的按钮 关闭窗口
    connect( myBtn ,&MyPushButton::clicked,this,&myWidget::close);
    //connect( myBtn ,&QPushButton::clicked,this,&QWidget::close); 与上面效果相同 只是用了父类
}

myWidget::~myWidget()
{
}

