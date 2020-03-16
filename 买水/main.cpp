#include <iostream>
using namespace std;
void fun(int m,int b,int g,int s)
{
    if(m==0&&b<2&&g<3)
        cout<<s<<endl;
    else
    {
        if (m>0)
        {
            m--;
            b++;
            g++;
            s++;
        }
        if(b>=2)
        {
            b=b-1;
            g++;
            s++;
        }
        if(g>=3)
        {
            g=g-2;
            b++;
            s++;
        }
        fun(m,b,g,s);
    }
}
int main()
{
    int m;
    int b = 0 ,g = 0,s = 0;
    cin>>m;
    fun(m,b,g,s);
}

