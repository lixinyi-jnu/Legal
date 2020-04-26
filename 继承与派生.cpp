/*【问题描述】

编写一个Shape类并派生出Circle类和Rectangle类，观察运行机制。

shape类有以下成员

1）私有成员m_ID

2）公有getter和setter

3）计算面积函数getArea()，返回0;

4）构造与析构函数

Circle类从shape类继承，并派生以下成员

1）私有成员r

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数

Rectangle类从shape类继承，并派生以下成员

1）私有成员h,w

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数


【样例输出】

Shape constructor called:1

Shape constructor called:2

Circle constructor called:2

Shape constructor called:3

Rectangle constructor called:3

Shape的面积0

Circle的面积50.2654

Rectangle的面积20

Rectangle destructor called:3

Shape destructor called:3

Circle destructor called:2

Shape destructor called:2

Shape destructor called:1
*/

#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
{
public:
    Shape(int a)
    {
        m_ID = a;
        cout<<"Shape constructor called:"<<getID()<<endl;
    }
    void setID(int a){m_ID = a;}
    int getID(){return m_ID;}
    int getArea(){return 0;}
    ~Shape()
    {
        cout<<"Shape destructor called:"<<getID()<<endl;
    }
private:
    int m_ID;
};




class Circle:public Shape
{
public:
    Circle(int a,int b):Shape(b)
    {
        r = a;
        cout<<"Circle constructor called:"<<getID()<<endl;
    }
    float getArea()
    {
        return pi*r*r;
    }
    void setr(int a){r = a;}
    int getr(){return r;}
    ~Circle()
    {
        cout<<"Circle destructor called:"<<getID()<<endl;
    }
private:
    int r;
};


class Rectangle:public Shape
{
public:
    Rectangle(int a,int b,int c):Shape(c)
    {
        h = a;
        w = b;
        cout<<"Rectangle constructor called:"<<getID()<<endl;
    }
    void seth(int a){h = a;}
    int geth(){return h;}
    void setw(int a){w = a;}
    int getw(){return w;}
    int getArea()
    {
        return h*w;
    }
    ~Rectangle()
    {
        cout<<"Rectangle destructor called:"<<getID()<<endl;
    }
private:
    int h,w;
};

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

