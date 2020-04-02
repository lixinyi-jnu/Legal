/*
 【问题描述】设计一个CRectangle类，其中包括CPoint类的两个对象成员，表示左上角和右下角的两个点。要求求解矩形的面积。

 注意，每个类的构造函数、拷贝构造函数需要输出“*** is called”,具体的请根据输出进行分析。

 main函数已经给定。

 【样例输出】

 # Define p1 ######

 CPoint contstructor with default value(0,0) is called.

 # Define p2 ######

 CPoint contstructor with default value(0,0) is called.

 # Define rect1 ######

 CPoint contstructor with default value(0,0) is called.

 CPoint contstructor with default value(0,0) is called.

 CRectangle default contstructor is called.

 # Define rect2 ######

 CPoint copy contstructor is called.

 CPoint copy contstructor is called.

 CPoint copy contstructor is called.

 CPoint copy contstructor is called.

 CRectangle contstructor with (CPoint,CPoint) is called.

 # Define rect3 ######

 CPoint contstructor with default value(0,0) is called.

 CPoint contstructor with default value(0,0) is called.

 CRectangle contstructor with (int,int,int,int) is called.

 # Define rect4 ######

 CPoint copy contstructor is called.

 CPoint copy contstructor is called.

 CRectangle copy contstructor is called.

 # Calculate area ######

 rect1面积为0

 rect2面积为200

 rect3面积为50

 rect4面积为200
*/
#include <iostream>
using namespace std;
//请在这里补充CPoint，CRectangle类的定义
class CPoint
{
public:
    CPoint(int a=0,int b=0)
    {
        x=a;
        y=b;
        cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
    }
    CPoint(CPoint &p)
    {
        x=p.x;
        y=p.y;
        cout<<"CPoint copy contstructor is called."<<endl;
    }
    int x,y;     //没有放在私有成员private里
};
class CRectangle
{
public:
    CRectangle()
    {
        x1=y1=x2=y2=0;
        cout<<"CRectangle default contstructor is called."<<endl;
    }
    CRectangle(CPoint a,CPoint b):p1(a),p2(b)
    {
        x1=p1.x;
        y1=p1.y;
        x2=p2.x;
        y2=p2.y;
        cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
    }
    CRectangle(int a,int b,int c,int d)
    {
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
    }
    CRectangle(CRectangle &p):p1(p.p1),p2(p.p2)
    {
        x1=p1.x;
        y1=p1.y;
        x2=p2.x;
        y2=p2.y;
        cout<<"CRectangle copy contstructor is called."<<endl;
    }
    int GetArea();
private:
    CPoint p1,p2;
    int x1,y1,x2,y2;
};
int CRectangle::GetArea()
{
    int l,d;
    l=x2-x1;
    d=y2-y1;
    return (l*d);
}


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



