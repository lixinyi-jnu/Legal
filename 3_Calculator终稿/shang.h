#ifndef SHANG_H
#define SHANG_H

#include <QMainWindow>
#include <QObject>

class Shang : public QMainWindow
{
    Q_OBJECT
public:
    explicit Shang(QWidget *parent = nullptr);
    Shang(int a,double b,double c,int d,double e);
    //按面积单价(总价、贷款额、贷款月数、月利率)
    Shang(int a,int b,double c);
    //按贷款总额(贷款额、贷款月数、月利率)
    double GetFirstmonth(){return firstmonth;}
    double GetLixi(){return lixi;}
    void Cal1();
    void Cal2();
    ~Shang(){}
    double total,month,firstmonth,lixi;  //贷款总额、贷款月数、总金额（用于单位面积）、第一个月首付、利息
    double percent,all;  //年利率




signals:

public slots:

//private:
//    double total,month,firstmonth,lixi;  //贷款总额、贷款月数、总金额（用于单位面积）、第一个月首付、利息
//    double percent,all;  //年利率
};

#endif // SHANG_H
