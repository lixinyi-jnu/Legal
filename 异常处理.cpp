/*
 【问题描述】

 请分析main函数，从exception类继承并派生两个异常类MyException1和MyException2，要求定义what成员函数，在what函数中，要求使用typeid，返回当前类的运行时的类型。

 请调试和分析该程序，熟练掌握关于异常捕获机制的使用。


 【输入形式】

 输入为一个1个整数，取值在1-4。
 【输出形式】

 输出包括两行

 第一行为输出的异常信息

 第二行为：Return to main()



 【样例输入1】

 1

 【样例输出1】

 exception: 12MyException1

 Return to main()



 【样例输入2】

 2

 【样例输出2】

 exception: 12MyException2

 Return to main()



 【样例输入3】

 3

 【样例输出3】

 exception: 0

 Return to main()



 【样例输入4】

 4

 【样例输出4】

 exception: basic_string::at: __n (which is 10) >= this->size() (which is 5)

 Return to main()


 */

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
using namespace std;


class MyException1:public exception
{
public:
    const char *what()const throw() //throw是异常借口说明 （）中无内容说明不抛掷任何类型异常 因为MyException1就是作为一个异常
    {
        const type_info &info1 = typeid(*this);
        return info1.name();
    }
};

class MyException2:public exception
{
public:
    const char *what()const throw()
    {
        const type_info &info1 = typeid(*this);
        return info1.name();
    }
};


int divide(int a,int b)
{
    if(b==0) throw b;
    return a/b;
}


int main()
{
    int id,k;
    cin>>id;
    char a;
    string s = "hello";
    try
    {
        switch (id) {
            case 1:
                throw MyException1(); //throw了一个MyException1()的对象，以默认构造函数够早的
                break;
            case 2:
                throw MyException2();
                break;
            case 3:
                k = divide(8,0);
                break;
            case 4:
                a=s.at(10);
                cout<<a<<endl;
                break;
            default:
                break;
        }
    }
    catch(MyException1 &e) //捕获到的是原始的对象e 不会再调用构造函数
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    catch(MyException2 &e)
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    catch(int &e)
    {
        cout<<"exception:"<<e<<endl;
    }
    catch(exception &e)
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    cout<<"Return to main()"<<endl;
    return 0;
}
