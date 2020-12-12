#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QStatusBar>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600,400);
    setWindowTitle("主析取范式计算器");

    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    QLabel *label = new QLabel("**请注意正确输入表达式**");
    stBar->addWidget(label);

    //this->setStyleSheet("QMainWindow{background-image: url(:/res/WechatIMG29.jpeg);}""QPushButton{background-image: url(:/res/WechatIMG38.jpeg);}""QListWidget{background-image: url(:/res/WechatIMG30.jpeg);}");
    this->setStyleSheet("QMainWindow{background-image: url(:/res/WechatIMG29.jpeg);}""QPushButton{background-image: url(:/res/WechatIMG38.jpeg);}");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    Dialog * dlg = new Dialog(this);  //防止一闪而过 创建到了堆区
    dlg->show();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//55号属性：在每次关闭小窗口之后 就把指针delete了 不耗费内存
}


void MainWindow::on_P1_returnPressed()
{
    exp += ui->P1->text().toUpper();
    temp_exp += ui->P1->text().toUpper();
    //alpha += ui->P1->text().toUpper();
    //alpha += "       ";       //5个空格
    alpha.append(ui->P1->text().toUpper());
}

void MainWindow::on_P2_returnPressed()
{
    exp += ui->P2->text().toUpper();
    temp_exp += ui->P2->text().toUpper();
    alpha.append(ui->P2->text().toUpper());
}

void MainWindow::on_P3_returnPressed()
{
    exp += ui->P3->text().toUpper();
    temp_exp += ui->P3->text().toUpper();
    alpha.append(ui->P3->text().toUpper());
}

void MainWindow::on_btn_fou_clicked()
{
    exp += "!";
    temp_exp += "┐";
    //ui->expression->addItem("┐");
}

void MainWindow::on_btn_hequ_clicked()
{
    exp += "*";
    temp_exp += "∧";
    //ui->expression->addItem("∧");
}

void MainWindow::on_btn_xiqu_clicked()
{
    exp += "|";
    temp_exp += "∨";
    //ui->expression->addItem("∨");
}

void MainWindow::on_btn_tiaojian_clicked()
{
    exp += "-";
    temp_exp += "→";
    //ui->expression->addItem("→");
}

void MainWindow::on_btn_shunag_clicked()
{
    exp += "=";
    temp_exp += "↔";
    //ui->expression->addItem("↔");
}

void MainWindow::on_btn_zuo_clicked()
{
    exp += "(";
    temp_exp += "(";
    //ui->expression->addItem("(");
}

void MainWindow::on_btn_you_clicked()
{
    exp += ")";
    temp_exp += ")";
    //ui->expression->addItem(")");
}

void MainWindow::on_pushButton_9_clicked()       //计算按钮
{
    alpha.append(temp_exp);   //原来alpha.append(exp);
    QString str;
    str = alpha.join("       ");
    ui->truthtable->addItem(str);


    QStringList res;
    res<<temp_exp;      //原来res<<exp;
    ui->expression->addItems(res);

    string temp = exp.toStdString();
    Calculate C(temp);
    C.Judge();     //判断原子命题个数
    C.DrawTable();
    C.BiToTen();



    //主析取范式小项的输出
    QStringList list;
    for(int i = 0; i < C.result.size(); i++)
    {
        QString str = QString("%1").arg(C.result[i]);
        list<<str;
    }
    QString str2;
    str2 = list.join(",");
    ui->result->addItem(str2);



    //真值表的输出
    for(int i = 0; i < pow(2, C.num); i++)
    {
        QStringList list;
        for(int j = 0; j <= C.num; j++)
        {
            QString str = QString("%1").arg(C.TruthTable[i][j]);
            list<<str;
        }
        QString str;
        str = list.join("        ");
        ui->truthtable->addItem(str);
    }
}



void MainWindow::on_pushButton_10_clicked()       //清零按键
{
    exp.clear();
    alpha.clear();
    ui->P1->clear();
    ui->P2->clear();
    ui->P3->clear();
    ui->expression->clear();
    ui->result->clear();
    ui->truthtable->clear();
}
