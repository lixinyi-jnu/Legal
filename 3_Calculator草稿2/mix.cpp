#include "mix.h"

Mix::Mix(QWidget *parent) : QMainWindow(parent)
{

}

void Mix::Calculate1()  //等额本金
{
    Shangdai.Cal1();
    Gongjijin.Cal1();
    firstsum =Shangdai.GetFirstmonth()+Gongjijin.GetFirstmonth();
    lixi = Shangdai.GetLixi()+Gongjijin.GetLixi();
}
void Mix::Calculate2()  //等额本息
{
    Shangdai.Cal2();
    Gongjijin.Cal2();
    firstsum =Shangdai.GetFirstmonth()+Gongjijin.GetFirstmonth();
    lixi = Shangdai.GetLixi()+Gongjijin.GetLixi();

}
