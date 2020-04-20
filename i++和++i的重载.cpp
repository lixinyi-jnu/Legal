#include <string>
#include <iostream>
using namespace std;

class Clock
{
public:
    Clock (int NewH=0,int NewM=0,int NewS=0)
    {
        Hour = NewH;
        Minute = NewM;
        Second = NewS;
    }
    void ShowTime()
    {
        cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
    }
    Clock& operator ++();   //++i
    Clock operator ++(int);   //i++
private:
    int Hour,Minute,Second;
};
Clock& Clock:: operator ++()
{
    Second++;
    if(Second>=60)
    {
        Second = Second -60;
        Minute++;
        if(Minute>=60)
        {
            Minute = Minute -60;
            Hour++;
            Hour = Hour %24;
        }
    }
    return *this;
}


Clock Clock::operator ++(int)   //i++后置
{
    Clock old = *this;
    ++(*this);      //将this增加
    return old;     //返回原来的内容 但其中的值已经在上一步增加了
}

int main()
{
    Clock myclock(23,59,59);
    myclock.ShowTime();
    (myclock++).ShowTime();
    (++myclock).ShowTime();
}
