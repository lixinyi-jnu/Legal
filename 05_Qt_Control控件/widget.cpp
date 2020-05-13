#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮 男默认选中
    ui->rBtnMan->setChecked(true);

    //选中女后 打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选中了女的";
    });

     //多选按钮 2是选中 0是未选中 1是半选
     connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
            qDebug()<<state;
    });


//     //利用ListWidget写诗
//     QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
//     //将一行诗放入ListWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignCenter);  //居中操作


     QStringList list;
     list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
     ui->listWidget->addItems(list);   //可以一次加入很多内容 但不能居中处理
}

Widget::~Widget()
{
    delete ui;
}

