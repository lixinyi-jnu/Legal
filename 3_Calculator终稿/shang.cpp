#include "shang.h"
#include <math.h>


Shang::Shang(QWidget *parent) : QMainWindow(parent)
{}


Shang::Shang(int a,double b,double c,int d,double e)    //按面积单价(总价、贷款额、贷款月数、月利率)
{
    all = a*b;
    total = all*(c/10);
    month = d * 12;
    percent = e/12;
}
Shang::Shang(int a,int b,double c)   //按贷款总额(贷款额、贷款月数、月利率)
{
    total = a*10000;
    month = b*12;
    percent = c/12;
}

void Shang::Cal1()  //等额本金
{
    firstmonth = (total/month)+total*percent;
    lixi = ((month+1)*total*percent)/2;
}
void Shang::Cal2()  //等额本息
{
    double a;
    a = pow((1+percent), month);
    firstmonth = (total*percent*a)/(a-1);
    lixi = (firstmonth * month)-total;
}
