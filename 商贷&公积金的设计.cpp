#include <math.h>
#include <iostream>
using namespace std;

class Shang
{
public:
    Shang(int a,int b,float c,int d,float e);
    Shang(int a,int b,float c);
    void Cal1();
    void Cal2();
    void Show1();
    void Show2();
    void Show3();
    void Show4();
private:
    float total,month,all,firstmonth,lixi;  //贷款总额、贷款月数、总金额（用于单位面积）、第一个月首付、利息
    double percent;  //利率
};
Shang::Shang(int a,int b,float c,int d,float e)    //按面积单价
{
    all = a*b;
    total = all*(c/10);
    month = d * 12;
    percent = e/12;
}
Shang::Shang(int a,int b,float c)   //按贷款总额
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
    float a;
    a = pow((1+percent), month);
    firstmonth = (total*percent*a)/(a-1);
    lixi = (firstmonth * month)-total;
}
void Shang::Show1()   //等额本金->面积单价
{
    cout<<"###"<<endl<<"首付:"<<int(all-total)<<"元"<<endl<<"首月月供:"<<int(firstmonth)<<"元"<<endl<<"每月递减:"<<int((total/month)*percent)<<"元"<<endl<<"贷款总额:"<<int(total)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(total+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}
void Shang::Show2()   //等额本息->面积单价
{
    cout<<"###"<<endl<<"首付:"<<int(all-total)<<"元"<<endl<<"每月月供:"<<int(firstmonth)<<"元"<<endl<<"贷款总额:"<<int(total)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(total+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}
void Shang::Show3()   //等额本金->总贷款
{
    cout<<"###"<<endl<<"每月月供:"<<int(firstmonth)<<"元"<<endl<<"每月递减:"<<int((total/month)*percent)<<"元"<<endl<<"贷款总额:"<<int(total)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(total+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}
void Shang::Show4()     //等额本息->总贷款
{
    cout<<"###"<<endl<<"每月月供:"<<int(firstmonth)<<"元"<<endl<<"贷款总额:"<<int(total)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(total+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}
double rate(int a)
{
    if (a<=5)
        return 0.0475;
    else
        return 0.049;
}

int main()
{
    int choose,way;
    cout<<"###请选择贷款方式:"<<endl<<"###商业贷款请输入1,公积金贷款请输入2,组合型贷款请输入3" <<endl;
    cin>>choose;
    if(choose == 1)
    {
        cout<<"###请选择计算方式:"<<endl<<"###根据面积单价计算请输入4,根据贷款总额计算请输入5"<<endl;
        cin>>way;
        if(way == 4)   //根据面积单价
        {
            int perArea,size,year,moneyway;
            double num,per;
            cout<<"###请输入房屋面积单价(元/平米):"<<endl;
            cin>>perArea;
            cout<<"###请输入房屋面积(平米):"<<endl;
            cin>>size;
            cout<<"###请输入按揭成数:"<<endl;
            cin>>num;
            cout<<"###请输入按揭年数:"<<endl;
            cin>>year;
            per = rate(year);
            cout<<"###年利率为:"<<per*100<<"%"<<endl;
            Shang b(perArea,size,num,year,per);
            cout<<"###请选择贷款方式:"<<endl<<"###等额本金请输入6,等额本息请输入7"<<endl;
            cin>>moneyway;
            if(moneyway == 6)    //等额本金
            {
                b.Cal1();
                b.Show1();
            }
            else if (moneyway == 7)   //等额本息
            {
                b.Cal2();
                b.Show2();
            }
            else
                cout<<"###请重新输入"<<endl;
        }
        if(way == 5)    //根据贷款总额
        {
            int sum,year,moneyway;
            double per;
            cout<<"###请输入贷款总额(万元):"<<endl;
            cin>>sum;
            cout<<"###请输入按揭年数:"<<endl;
            cin>>year;
            per = rate(year);
            cout<<"###年利率为:"<<per*100<<"%"<<endl;
            Shang b(sum,year,per);
            cout<<"###请选择贷款方式:"<<endl<<"###等额本金请输入6,等额本息请输入7"<<endl;
            cin>>moneyway;
            if(moneyway == 6)   //等额本金
            {
                b.Cal1();
                b.Show3();
            }
            else if (moneyway == 7)  //等额本息
            {
                b.Cal2();
                b.Show4();
            }
            else
                cout<<"###请重新输入"<<endl;
        }
    }
}
