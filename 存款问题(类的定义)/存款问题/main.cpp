#include <iostream>
#include <iomanip>
using namespace std;
//定义Account类
class Account
{
public:
    void init(const char *c ,const char *b,const char *str,int m,double n)
    {
        int i,j,a;
        for(i = 0;c[i]!='\0';i++)
            number[i] = c[i];
        for(j = 0;b[j]!='\0';j++)
            name[j] = b[j];
        for(i = 0;str[i]!='\0';i++)
            gender[i] = str[i];
        age = m;
        a = n*1000;
        if(a%10!=0)
        {
            cout<<"您输入的金额不合法"<<endl;
            saving = 0;
        }
        else
            saving = n;
    }
    void printmoney()
    {
        cout<<name<<"的存款为"<<fixed<<setprecision(2)<<saving<<endl;
    }
    void deposit(double in)
    {
        int a;
        a = in * 1000;
        if(a%10!=0)
            cout<<"您输入的金额不合法"<<endl;
        else
            saving += in;
    }
    void withdraw(double out)
    {
        int a;
        a = out*1000;
        if(a%10!=0)
            cout<<"您输入的金额不合法"<<endl;
        else
        {
            saving -= out;
            if(saving<0)
            {
                cout<<"您的存款金额不足"<<endl;
                saving += out;
            }
        }
        
    }
private:
    char number[20],name[15],gender[1];
    int age;
    double saving;
};
int main()
{
    Account tom;
    tom.init("32020320011001876X","Tom Black","男",19,2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);
    tom.printmoney();
    tom.deposit(10000);
    tom.printmoney();
    tom.withdraw(10001);
    tom.printmoney();
    tom.withdraw(10000.123);
    tom.printmoney();
    tom.withdraw(10000.9);
    tom.printmoney();
    Account jerry;
    jerry.init("320203200910116569","Jerry Black","女",11,100.956);
    jerry.printmoney();
}
