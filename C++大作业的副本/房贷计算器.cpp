#include <math.h>
#include <iostream>
using namespace std;

class Shang
{
public:
    Shang(int a,int b,float c,int d,float e);
    Shang(int a,int b,float c);
    float GetFirstmonth(){return firstmonth;}
    float GetLixi(){return lixi;}
    void Cal1();
    void Cal2();
    void Show1();
    void Show2();
    void Show3();
    void Show4();
    ~Shang(){};
private:
    float total,month,all,firstmonth,lixi;  //贷款总额、贷款月数、总金额（用于单位面积）、第一个月首付、利息
    double percent;  //年利率
};
Shang::Shang(int a,int b,float c,int d,float e)    //按面积单价(总价、贷款额、贷款月数、月利率)
{
    all = a*b;
    total = all*(c/10);
    month = d * 12;
    percent = e/12;
}
Shang::Shang(int a,int b,float c)   //按贷款总额(贷款额、贷款月数、月利率)
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



class Mix
{
public:
    Mix(int a,int b,int c,double d,double e):Shangdai(a,c,d),Gongjijin(b,c,e)    //商贷金额、公积金金额、年数、商贷利率、公积金利率
    {
        month = c*12;
        Shang = a*10000;
        Gong = b*10000;
        Sper = d/12;
        Gper = e/12;
    }
    void Show1();
    void Show2();
    void Calculate1();
    void Calculate2();
    ~Mix(){};
private:
    Shang Shangdai,Gongjijin;  //定义两个对象
    int month,Shang,Gong;   //贷款月数，商贷金额，公积金金额，商贷利率，公积金利率
    float firstsum,lixi,Sper,Gper;   //第一个月还款、利息
};
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
void Mix::Show1()
{
    cout<<"###"<<endl<<"每月月供:"<<int(firstsum)<<"元"<<endl<<"每月递减:"<<int((Shang/month*Sper)+(Gong/month*Gper))<<"元"<<endl<<"贷款总额:"<<int(Shang+Gong)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(Shang+Gong+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}
void Mix::Show2()
{
    cout<<"###"<<endl<<"每月月供:"<<int(firstsum)<<"元"<<endl<<"贷款总额:"<<int(Shang+Gong)<<"元"<<endl<<"支付利息:"<<int(lixi)<<"元"<<endl<<"还款总额:"<<int(Shang+Gong+lixi)<<"元"<<endl<<"还款月数:"<<month<<"个月"<<endl;
}


double rateBusiness(int a)
{
    if (a<=5)
        return 0.0475;
    else
        return 0.0490;
}


double rateGong(int a)
{
    if (a<=5)
        return 0.0275;
    else
        return 0.0325;
}




int main()
{
    int choose,way;
    cout<<"###请选择贷款方式:"<<endl<<"###商业贷款请输入1,公积金贷款请输入2,组合型贷款请输入3" <<endl;
    cin>>choose;
    if((choose == 1)||(choose == 2))
    {
        cout<<"###请选择计算方式:"<<endl<<"###根据面积单价计算请输入4,根据贷款总额计算请输入5"<<endl;
        cin>>way;
        if(way == 4)   //根据面积单价
        {
            int perArea,year,moneyway;   //面积单价、面积、贷款年数、贷款方式
            double num,per,size;     //按揭成数、年利率
            cout<<"###请输入房屋面积单价(元/平米):"<<endl;
            cin>>perArea;
            cout<<"###请输入房屋面积(平米):"<<endl;
            cin>>size;
            cout<<"###请输入按揭成数:"<<endl;
            cin>>num;
            cout<<"###请输入按揭年数(不能大于30年):"<<endl;
            cin>>year;
            if(choose == 1)
            {
                per = rateBusiness(year);
                cout<<"###商业贷款年利率为:"<<per*100<<"%"<<endl;
            }
            else
            {
                per = rateGong(year);
                cout<<"###公积金贷款年利率为:"<<per*100<<"%"<<endl;
            }
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
            int sum,year,moneyway;   //贷款总额、贷款年数、贷款方式
            double per;  //年利率
            cout<<"###请输入贷款总额(万元):"<<endl;
            cin>>sum;
            cout<<"###请输入按揭年数(不能大于30年):"<<endl;
            cin>>year;
            if(choose == 1)
            {
                per = rateBusiness(year);
                cout<<"###商业贷款年利率为:"<<per*100<<"%"<<endl;
            }
            else
            {
                per = rateGong(year);
                cout<<"###公积金贷款年利率为:"<<per*100<<"%"<<endl;
            }
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
    if(choose == 3)
    {
        int S,G,year,moneyway;   //商贷金额、公积金金额、贷款年数
        cout<<"###请输入商业贷款额(万元):"<<endl;
        cin>>S;
        cout<<"###请输入公积金贷款额(万元):"<<endl;
        cin>>G;
        cout<<"###请输入按揭年数(不能大于30年):"<<endl;
        cin>>year;
        double Sper,Gper;   //商贷利率、公积金利率
        Sper = rateBusiness(year);
        Gper = rateGong(year);
        cout<<"###商业贷款年利率为:"<<Sper*100<<"%"<<endl;
        cout<<"###公积金贷款年利率为:"<<Gper*100<<"%"<<endl;
        cout<<"###请选择贷款方式:"<<endl<<"###等额本金请输入6,等额本息请输入7"<<endl;
        cin>>moneyway;
        Mix m(S, G, year, Sper, Gper);
        if(moneyway == 6)   //等额本金
        {
            m.Calculate1();
            m.Show1();
        }
        if(moneyway == 7)   //等额本息
        {
            m.Calculate2();
            m.Show2();
        }
    }
}
