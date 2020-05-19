#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
public:
    Array (int n){}
    void input(int n)
    {
        for(int i=0;i<n;i++)
        {
            T k;
            cin>>k;
            a.push_back(k);
        }
    }
    T& operator [](int i)
        {
            return a[i];
        }
private:
    vector<T>a;
};


class Fract
{
public:
    Fract()
    {
        fenzi = 0;
        fenmu = 1;
    }
    Fract(int n,int m)
    {
        if(n == 0)
        {
            fenzi = 0;
            fenmu = 1;
        }
        else
        {
            int m0,n0;
            m0 = m;
            n0 = n;
            while (m%n!=0)
            {
                int temp = m;
                m = n;
                n = temp%n;
            }
            fenzi = n0/n;
            fenmu = m0/n;

        }
    }


    void show()
    {
        if(fenzi==0)
        {
            fenzi = 0;
            fenmu = 1;
        }
        else
        {
            int m=fenmu,n=fenzi;
            int m0=m,n0=n;
            while (m%n!=0)
            {
                int temp = m;
                m = n;
                n = temp%n;
            }
            fenzi = n0/n;
            fenmu = m0/n;
        }
        
        if(fenzi == 0)
        {
           cout<<0<<endl;
        }
        else if(fenmu == 1)
        {
           cout<<fenzi<<endl;
        }
        else
        {
            if(fenzi<0&&fenmu>0)
                cout<<"-"<<fenzi<<"/"<<fenmu<<endl;
            else if(fenzi>0&&fenmu<0)
                cout<<"-"<<fenzi<<"/"<<fenmu<<endl;
            else if(fenzi>0&&fenmu>0)
                cout<<fenzi<<"/"<<fenmu<<endl;
            else if(fenzi<0&&fenmu<0)
                cout<<fenzi<<"/"<<fenmu<<endl;
        }
    }
    Fract operator += (Fract c)
    {
        Fract temp;
        temp.fenmu = fenmu * c.fenmu;
        temp.fenzi = fenzi*c.fenmu + c.fenzi*fenmu;
        return *this = temp;
    }
    friend istream& operator >> (istream& input,Fract& c)  //定义重载运算符“>>”
    {
        input>>c.fenzi>>c.fenmu;
       return input;
    }
private:
    int fenzi,fenmu;
};

int main()
{
    unsigned int n;
    cin>>n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for(unsigned int i =0; i < n; i++)
        dbsum += db[i];
    cout<<dbsum<<endl;
    
    cin>>n;
    Array<Fract>fr(n);
    fr.input(n);
    Fract frsum(0,1);
    for(unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
