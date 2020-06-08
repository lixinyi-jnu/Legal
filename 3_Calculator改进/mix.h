#ifndef MIX_H
#define MIX_H

#include <QMainWindow>
#include <shang.h>

class Mix : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mix(QWidget *parent = nullptr);

    Mix(int a,int b,int c,double d,double e):Shangdai(a,c,d),Gongjijin(b,c,e)    //商贷金额、公积金金额、年数、商贷利率、公积金利率
    {
        month = c*12;
        Shang = a*10000;
        Gong = b*10000;
        Sper = d/12;
        Gper = e/12;
    }
    void Calculate1();
    void Calculate2();
    ~Mix(){}

    Shang Shangdai,Gongjijin;  //定义两个对象
    int month,Shang,Gong;   //贷款月数，商贷金额，公积金金额，商贷利率，公积金利率
    double firstsum,lixi,Sper,Gper;   //第一个月还款、利息
signals:

public slots:


//private:
//    Shang Shangdai,Gongjijin;  //定义两个对象
//    int month,Shang,Gong;   //贷款月数，商贷金额，公积金金额，商贷利率，公积金利率
//    double firstsum,lixi,Sper,Gper;   //第一个月还款、利息
};

#endif // MIX_H
