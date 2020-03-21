/*
 【问题描述】声明一个表示时间的类CTime，可以精确表示年、月、日、小时、分、秒，请计算两个日期对象之间相隔的天数。
 要求：

 1、包括私有成员年、月、日、小时、分、秒。

 2、请使用构造函数实现的类的初始化工作，并判断日期和时间的有效性。年月日时分秒应该在正确的范围内。考虑闰年时候二月份的情况。时间的格式是xx:xx:xx,小时不是超过23，分钟和秒不能超过59。

       1）如果日期无效，则输出 “date error! ”  并将年、月、日、小时、分、秒置为0。

       2）如果时间无效，则输出 “time error! ”  并将年、月、日、小时、分、秒置为0。

       3）如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒。

       4）构造函数的三个参数：小时、分、秒 设计为默认形成，其默认值为0。

       5)  输出"构造函数被调用"

 3、请设计一个拷贝构造函数，实现将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”

 4、请设计一个析构函数，同时输出“析构函数被调用”

 5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。
 
 6、设计一个成员函数 showTime()，用于显示日期，显示格式为：2020/3/12 11:50:20
*/
#include <iostream>
using namespace std;
class CTime
{
private:
    int year,month,day,hour,minute,second;
public:
    CTime(int y,int m,int d,int h = 0,int min = 0,int s = 0);
    CTime(CTime &p)
    {
        year = p.year;
        month = p.month;
        day = p.day;
        cout<<"拷贝构造函数被调用"<<endl;
    }
    void showTime();
    int leapyear(int year);
    int dayDiff(CTime t);
    int isvalid()
    {
        if(year!=0)
            return 1;
        else
            return 0;
    }
    ~CTime()
    {
        cout<<"析构函数被调用"<<endl;
    }
};
CTime::CTime(int y,int m,int d,int h,int min,int s)
{
    year=y;
    month=m;
    day=d;
    hour=h;
    minute=min;
    second=s;
    if(month==4||month==6||month==9||month==11)
    {
        if(day>30)
        {
            if(hour>23||minute>59||second>59)
                cout<<"date and time error!"<<endl;
             else
                 cout<<"date error!"<<endl;
            year=month=day=hour=minute=second=0;
        }
    }
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(day>31)
        {
            if(hour>23||minute>59||second>59)
                cout<<"date and time error!"<<endl;
            else
                cout<<"date error!"<<endl;
            year=month=day=hour=minute=second=0;
        }
    }
    if(month==2)
    {
        int k = leapyear(year);
        if(k==1)
        {
            if(day>29)
            {
                if(hour>23||minute>59||second>59)
                    cout<<"date and time error!"<<endl;
                else
                    cout<<"date error!"<<endl;
                year=month=day=hour=minute=second=0;
            }
        }
        if(k==2)
        {
            if(day>28)
            {
                if(hour>23||minute>59||second>59)
                    cout<<"date and time error!"<<endl;
                else
                    cout<<"date error!"<<endl;
                year=month=day=hour=minute=second=0;
            }
        }
    }
    if(hour>23||minute>59||second>59)
    {
        cout<<"time error!"<<endl;
        year=month=day=hour=minute=second=0;
    }
    cout<<"构造函数被调用"<<endl;
}
void CTime::showTime()
{
    cout<<year<<"/"<< month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
int CTime::leapyear(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))    //是闰年
        return 1;   //是闰年
    else
        return 2;   //不是闰年
}
int CTime::dayDiff(CTime t)
{
    int monthsum = 0,monthsum2 = 0,i,k,period,ly,daysum = 0;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(t.year>year)
    {
        for(i=0;i<(t.month-1);i++)
            monthsum += a[i];
        monthsum += t.day;
        if(t.month>2)
        {
            k=leapyear(t.year);
            if(k==1)
            {
                monthsum++;
            }
        }
        period = t.year - year;   //period=2020-2000=20
        ly = (period-1)/4;   //ly=2020-2000=20-1=19/4=4
        if(ly!=0)
        {
            daysum = (1+ly)*366+(period-1-ly)*365+monthsum-1;
            return daysum;
        }
        else
        {
            for(i=0;i<month-1;i++)
                monthsum2 += a[i];
            monthsum2 += day;
            daysum = monthsum+(period-1)*365+(365-monthsum2);
            return daysum;
        }
    }
    else if(t.year<year)
    {
        for(i=0;i<(month-1);i++)
            monthsum += a[i];
        monthsum += day;
        if(month>2)
        {
            k=leapyear(year);
            if(k==1)
            {
                monthsum++;
            }
        }
        period = year - t.year;
        ly = (period-1)/4;
        if(ly!=0)
        {
            daysum = monthsum+ly*366+(period-ly)*365;
            return daysum;
        }
        else
        {
            for(i=0;i<(t.month-1);i++)
                monthsum2 += a[i];
            monthsum2 += t.day;
            daysum = monthsum+(period-1)*365+(365-monthsum2);
            return daysum;
        }
    }
    else
    {
        if(month>t.month)
        {
            for(i=1;i<month-1;i++)
                daysum += a[i];
            daysum += day+31;
            return daysum;
        }
        else
        {
            for(i=1;i<t.month-1;i++)
                daysum += a[i];
            daysum += t.day+31;
            return daysum;
        }
    }
}

int main()
{
    int year,month,day,hour,minute,second;
    cin>>year>>month>>day>>hour>>minute>>second;
    CTime t1(year,month,day,hour,minute,second);
    t1.showTime();
    CTime t2(2000,1,1); //利用默认形参将时间初始化为00:00:00
    if(t1.isvalid())      //如果日期合理，则计算天数
    {
        int days = 0;
        days=t1.dayDiff(t2);
        cout<<"这两天相隔了"<<days<<"天"<<endl;
        days=t2.dayDiff(t1);
        cout<<"这两天相隔了"<<days<<"天"<<endl;
    }
}
