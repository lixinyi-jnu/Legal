#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculate.h"
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_9_clicked();

    void on_btn_fou_clicked();

    void on_btn_hequ_clicked();

    void on_btn_xiqu_clicked();

    void on_btn_tiaojian_clicked();

    void on_btn_shunag_clicked();

    void on_btn_zuo_clicked();

    void on_btn_you_clicked();

    void on_P1_returnPressed();

    void on_P2_returnPressed();

    void on_P3_returnPressed();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QString exp;        //表达式
    QString temp_exp;    //显示的表达式值
    QStringList alpha;      //保存命题变元

};
#endif // MAINWINDOW_H
