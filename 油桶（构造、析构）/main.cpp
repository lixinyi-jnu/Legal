#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.1415926;
class cylinder
{
public:
    cylinder(double a,double b);
    double getvolumn() const
    {
        double V;
        V=PI*r*r*h;
        return V;
    }
    double getarea() const
    {
        double S;
        S=2*PI*r*(r+h);
        return S;
    }
    ~cylinder();
private:
    double r,h;
};
cylinder::cylinder(double a,double b)
{
    h = a;
    r = b;
    cout<<"构造函数被调用"<<endl;
}
cylinder::~cylinder()
{
    cout<<"析构函数被调用"<<endl;
}
int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}
