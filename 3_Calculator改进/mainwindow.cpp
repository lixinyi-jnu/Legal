#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStatusBar>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600,400);
    setWindowTitle("房贷计算器");

    //设置默认定位 all页面
    ui->stackedWidget->setCurrentIndex(0);

    //设置按钮
    connect(ui->btn_SArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btn_Stotal,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btn_GArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_GTotal,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->btn_Mix,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(5);
    });

    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    QLabel *label = new QLabel("**点击利率对话框自动显示相应利率**");
    stBar->addWidget(label);


    //设置返回按钮
    connect(ui->btn_back1,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_back2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_back3,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_back4,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_back5,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });


}


MainWindow::~MainWindow()
{
    delete ui;
}
//商贷面积单价的实现

void MainWindow::on_Scombox1_currentIndexChanged(int index)  //下拉框按揭成数初始化
{
    num = index;
}


void MainWindow::on_Sline1_editingFinished()  //房屋单价的槽函数
{
    perArea = ui->Sline1->text().toInt();
//    if(perArea<=0)
//    {
//       QMessageBox::warning(this,"warning","输入不合法！");
//    }
}


void MainWindow::on_Sline2_editingFinished()  //面积的槽函数
{
    size = ui->Sline2->text().toDouble();
//    if(size<=0)
//    {
//       QMessageBox::warning(this,"warning","输入不合法！");
//    }
}



void MainWindow::on_Sline3_returnPressed() //按揭年数的槽函数
{
    year = ui->Sline3->text().toInt();
    if(year<=5&&year>0)
    {
        ui->Sline4->setText("4.75%");
        per = 0.0475;
    }
    else if(year>5&&year<=30)
    {
        ui->Sline4->setText("4.90%");
        per = 0.0490;
    }
    else if(year>30)
    {
        QMessageBox::warning(this,"warning","按揭年数不能超过30年");
        ui->Sline4->setText("----");
    }
}

void MainWindow::on_btn1_clicked()     //等额本金按钮
{
    Shang b1(perArea,size,num,year,per);
    b1.Cal1();
    QString str1 = QString("首付：%1 元").arg(int(b1.all-b1.total));
    QString str2 = QString("首月月付：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("每月递减：%1 元").arg(int((b1.total/b1.month)*b1.percent));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本金"<<str1<<str2<<str3<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_2->addItems(list);

}

void MainWindow::on_btn2_clicked()   //等额本息按钮
{
    Shang b1(perArea,size,num,year,per);
    b1.Cal2();
    QString str1 = QString("首付：%1 元").arg(int(b1.all-b1.total));
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str4 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str5 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str6 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本息"<<str1<<str2<<str3<<str4<<str5<<str6<<" ";
    ui->listWidget_2->addItems(list);
}


//商贷按贷款总额的实现


void MainWindow::on_STline1_editingFinished()   //贷款总额的初始化
{
    sum = ui->STline1->text().toInt();
}

void MainWindow::on_STline2_returnPressed()  //按揭年数
{
    year = ui->STline2->text().toInt();
    if(year<=5)
    {
        ui->STline3->setText("4.75%");
        per = 0.0475;
    }
    else if(year>5&&year<=30)
    {
        ui->STline3->setText("4.90%");
        per = 0.0490;
    }
    else if(year>30)
    {
        QMessageBox::warning(this,"warning","按揭年数不能超过30年");
        ui->STline3->setText("----");
    }
}

void MainWindow::on_btn3_clicked()  //等额本金
{
    Shang b1(sum,year,per);
    b1.Cal1();
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("每月递减：%1 元").arg(int((b1.total/b1.month)*b1.percent));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本金"<<str2<<str3<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_3->addItems(list);
}



void MainWindow::on_btn4_clicked()  //等额本息
{
    Shang b1(sum,year,per);
    b1.Cal2();
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本息"<<str2<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_3->addItems(list);
}


//公积金面积单价的实现

void MainWindow::on_Gline1_editingFinished()
{
    perArea = ui->Gline1->text().toInt();
}

void MainWindow::on_Gline2_editingFinished()
{
    size = ui->Gline2->text().toDouble();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    num = index;
}



void MainWindow::on_Gline3_returnPressed()
{
    year = ui->Gline3->text().toInt();
    if(year<=5)
    {
        ui->Gline4->setText("2.75%");
        per = 0.0275;
    }
    else if(year>5&&year<=30)
    {
        ui->Gline4->setText("3.25%");
        per = 0.0325;
    }
    else if(year>30)
    {
        QMessageBox::warning(this,"warning","按揭年数不能超过30年");
        ui->Gline4->setText("----");
    }
}

void MainWindow::on_btn5_clicked()
{
    Shang b1(perArea,size,num,year,per);
    b1.Cal1();
    QString str1 = QString("首付：%1 元").arg(int(b1.all-b1.total));
    QString str2 = QString("首月月付：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("每月递减：%1 元").arg(int((b1.total/b1.month)*b1.percent));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本金"<<str1<<str2<<str3<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_4->addItems(list);
}

void MainWindow::on_btn6_clicked()
{
    Shang b1(perArea,size,num,year,per);
    b1.Cal2();
    QString str1 = QString("首付：%1 元").arg(int(b1.all-b1.total));
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str4 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str5 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str6 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本息"<<str1<<str2<<str3<<str4<<str5<<str6<<" ";
    ui->listWidget_4->addItems(list);
}

//公积金按贷款总额的实现


void MainWindow::on_GTline1_editingFinished()
{
    sum = ui->GTline1->text().toInt();
}

void MainWindow::on_GTline2_returnPressed()
{
    year = ui->GTline2->text().toInt();
    if(year<=5)
    {
        ui->GTline3->setText("2.75%");
        per = 0.0275;
    }
    else if(year>5&&year<=30)
    {
        ui->GTline3->setText("3.25%");
        per = 0.0325;
    }
    else if(year>30)
    {
        QMessageBox::warning(this,"warning","按揭年数不能超过30年");
        ui->GTline3->setText("----");
    }
}


void MainWindow::on_btn7_clicked()
{
    Shang b1(sum,year,per);
    b1.Cal1();
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str3 = QString("每月递减：%1 元").arg(int((b1.total/b1.month)*b1.percent));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本金"<<str2<<str3<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_5->addItems(list);
}


void MainWindow::on_btn8_clicked()
{
    Shang b1(sum,year,per);
    b1.Cal2();
    QString str2 = QString("每月月供：%1 元").arg(int(b1.firstmonth));
    QString str4 = QString("贷款总额：%1 元").arg(int(b1.total));
    QString str5 = QString("支付利息：%1 元").arg(int(b1.lixi));
    QString str6 = QString("还款总额：%1 元").arg(int(b1.total+b1.lixi));
    QString str7 = QString("还款月数：%1 个月").arg(b1.month);
    QStringList list;
    list<<"等额本息"<<str2<<str4<<str5<<str6<<str7<<" ";
    ui->listWidget_5->addItems(list);
}


//组合型贷款
void MainWindow::on_Mline1_editingFinished()  //商贷额初始化
{
    S = ui->Mline1->text().toInt();
}

void MainWindow::on_Mline3_editingFinished()  //公积金额初始化
{
    G = ui->Mline3->text().toInt();
}

void MainWindow::on_Mline5_returnPressed() //按揭年数
{
    year = ui->Mline5->text().toInt();
    if(year<=5)
    {
        ui->Mline2->setText("4.75%");
        ui->Mline4->setText("2.75%");
        Sper = 0.0475;
        Gper = 0.0275;
    }
    else if(year>5&&year<=30)
    {
        ui->Mline2->setText("4.90%");
        ui->Mline4->setText("3.25%");
        Sper = 0.0490;
        Gper = 0.0325;
    }
    else if(year>30)
    {
        QMessageBox::warning(this,"warning","按揭年数不能超过30年");
        ui->Mline2->setText("----");
        ui->Mline4->setText("----");
    }
}



void MainWindow::on_btn9_clicked()  //等额本金
{
    Mix m(S,G,year,Sper,Gper);
    m.Calculate1();
    QString str1 = QString("每月月供：%1 元").arg(int(m.firstsum));
    QString str2 = QString("每月递减：%1 元").arg(int((m.Shang/m.month*m.Sper)+(m.Gong/m.month*m.Gper)));
    QString str3 = QString("贷款总额：%1 元").arg(int(m.Shang+m.Gong));
    QString str4 = QString("支付利息：%1 元").arg(int(m.lixi));
    QString str5 = QString("还款总额：%1 元").arg(int(m.Shang+m.Gong+m.lixi));
    QString str6 = QString("还款月数：%1 个月").arg(m.month);
    QStringList list;
    list<<"等额本金"<<str1<<str2<<str3<<str4<<str5<<str6<<" ";
    ui->listWidget->addItems(list);
}


void MainWindow::on_btn10_clicked()  //等额本息
{
    Mix m(S,G,year,Sper,Gper);
    m.Calculate2();
    QString str1 = QString("每月月供：%1 元").arg(int(m.firstsum));
    QString str3 = QString("贷款总额：%1 元").arg(int(m.Shang+m.Gong));
    QString str4 = QString("支付利息：%1 元").arg(int(m.lixi));
    QString str5 = QString("还款总额：%1 元").arg(int(m.Shang+m.Gong+m.lixi));
    QString str6 = QString("还款月数：%1 个月").arg(m.month);
    QStringList list;
    list<<"等额本息"<<str1<<str3<<str4<<str5<<str6<<" ";
    ui->listWidget->addItems(list);

}








