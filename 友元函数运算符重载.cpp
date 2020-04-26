/*
 【问题描述】

 请定义一个复数类，将+/-运算符重载为友元函数，实现复数与复数的加减及复数与浮点数的加减。

 请根据给定的main函数，设计Complex类。

 【样例输出】

 a+b=(4)+(3i)

 a-b=(2)+(5i)

 a+100=(103)+(4i)

 a-2.5=(0.5)+(4i)

 100+a=(103)+(4i)

 2.5-a=(-0.5)+(-4i)


 */

#include <iostream>
using namespace std;
class Point
{
    int real,imag;
public:
    Point(int a,int b)
    {
        real = a;
        imag = b;
    }
    Point operator ++ (int)
    {
        Point old = *this;
        ++(*this);
        return old;
    }
    Point& operator ++()
    {
        real++;
        imag++;
        return *this;
    }
    friend ostream &operator<<( ostream &output,
                                          const Point &D )
         {
             output << "("<<D.real<<","<<D.imag<<")"<<endl;
            return output;
         }
    
};

int main()
{
    Point a(1,3);
    cout<<a;
    cout<<a++;
    cout<<++a;
    return 0;
}

