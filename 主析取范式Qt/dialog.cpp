#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setFixedSize(600,400);
    setWindowTitle("帮助文档");
    this->setStyleSheet("QTreeWidget{background-image: url(:/res/WechatIMG29.jpeg);}""QDialog{background-image: url(:/res/WechatIMG29.jpeg);}");
}

Dialog::~Dialog()
{
    delete ui;
}


//void Dialog:: paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    QPixmap pix;
//    pix.load(":/res/WechatIMG29.jpeg");
//    painter.drawPixmap(0,0,this->width(),this->height(),pix);
//}
