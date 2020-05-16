#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int k = mon.Get_Shang();
    double x;
    int y;
    x=ui->lineEdit->text().toDouble();
    y= ui->comboBox->currentIndex();

    QString str1 = QString ("贷款金额为：%1").arg(a);
    QString str2 = QString ("还款月数为：%1").arg(b);
    QString str3 = QString ("利息为：%1").arg(mon.Get_Gong());
    QString str4 = QString ("总额：%1").arg(k);
    QString str5 = QString ("自己输入的：%1").arg(x);
    QString str6 = QString ("下拉框里的：%1").arg(y);
    QStringList list;
    list<<str1<<str2<<str3<<str4<<str5<<str6;
    ui->listWidget->addItems(list);

    connect(ui->btn1,&QPushButton::clicked,[=](){
        QStringList list2;
        list2<<str1<<str2;
        ui->listWidget->addItems(list);

    });

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index>=3)
    {
        ui->lineEdit_2->setText("4.75%");
    }
    else
        ui->lineEdit_2->setText("Error！");
}

void MainWindow::on_lineEdit_editingFinished()
{

}
