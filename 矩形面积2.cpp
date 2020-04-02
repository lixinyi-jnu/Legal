/*
 本次的区别在于CPoint中将x、y放在了私有变量y里，在CRectangle中删去了x1、2和y1、2.
 CRectangle中全部用了CPoint的对象 
*/
#include <iostream>
using namespace std;
class CPoint
{
public:
    CPoint()
    {
        x = y = 0;
        cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
    }
    CPoint(int a,int b)
    {
        x = a;
        y = b;
        cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
    }
    CPoint(CPoint &p)
    {
        x = p.x;
        y = p.y;
        cout<<"CPoint copy contstructor is called."<<endl;
    }
    int Get_x(){return x;}
    int Get_y(){return y;}
private:
    int x,y;
};
class CRectangle
{
public:
    CRectangle()
    {
        cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
    }
    CRectangle(CPoint a,CPoint b):p1(a),p2(b)
    {
        cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
    }
    CRectangle(int a,int b,int c,int d):p1(a,b),p2(c,d)//可以用这样的方式再次调用CPoint的构造函数
    {
        cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
    }
    CRectangle(CRectangle &p):p1(p.p1),p2(p.p2)
    {
        cout<<"CRectangle copy contstructor is called."<<endl;
    }
    int GetArea()
    {
        int d = p1.Get_x()-p2.Get_x();
        int l = p1.Get_y()-p2.Get_y();
        return d*l;
    }
private:
    CPoint p1,p2;
};
int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}

