#include <iostream>
#include <iomanip>
using namespace std;

struct complex
{
    double r;
    double i;
};
complex add(complex m, complex n)
{
    complex c;
    c.r = m.r +n.r;
    c.i = m.i +n.i;
    return c;
}
complex add(complex m, double n)
{
    complex c;
    c.r = m.r + n;
    c.i = m.i;
    return c;
}
complex add(double m, complex n)
{
    complex c;
    c.r = m + n.r;
    c.i = n.i;
    return c;
}
int main()
{
    double num;
    complex a,b,c;
    cin >> a.r>> a.i;
    cin >> b.r>> b.i;
    cin>> num;
    c = add(a,b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a,num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num,b);
    cout << c.r << "+" << c.i << "i" << endl;
    
}
