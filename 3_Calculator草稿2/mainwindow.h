#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <shang.h>
#include <mix.h>

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

    void on_Scombox1_currentIndexChanged(int index);


    void on_Sline1_editingFinished();

    void on_Sline2_editingFinished();

    void on_Sline3_editingFinished();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_STline1_editingFinished();

    void on_STline2_editingFinished();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_Gline1_editingFinished();

    void on_Gline2_editingFinished();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_Gline3_editingFinished();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_GTline1_editingFinished();

    void on_GTline2_editingFinished();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_Mline1_editingFinished();

    void on_Mline3_editingFinished();

    void on_Mline5_editingFinished();

    void on_btn9_clicked();

    void on_btn10_clicked();


private:
    Ui::MainWindow *ui;
    int sum,num,perArea,year,moneyway;   //面积单价、面积、贷款年数、贷款方式
    double per,size;     //按揭成数、年利率
    int S,G; //商贷金额、公积金金额、贷款年数
    double Sper,Gper;   //商贷利率、公积金利率
};
#endif // MAINWINDOW_H
