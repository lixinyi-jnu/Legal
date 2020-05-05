/*
 【问题描述】

 请定义一个Point类，将前置++和后置++运算符重载为成员函数，实现成员变量m_x和m_y的加一操作。

 同时重载流插入运算符，实现对Point类对象的格式化输出。例如

 Point p；

 cout<<p;

 输出结果为：

 （0,0）



 请根据给定的main函数，设计Point类。
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

