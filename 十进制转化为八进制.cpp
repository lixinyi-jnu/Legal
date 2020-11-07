/*
【问题描述】对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
【输入形式】非负十进制整数
【输出形式】相应十进制整数转换后的八进制正整数，若输入不符合要求，提示错误，重新输入
【样例输入】5548
【样例输出】12654
【样例说明】先判断输入是否符合非负正整数要求
*/
#include<iostream>
using namespace std;
#define N 100



int main()
{
    int n,result,a[N];
    int k = 0;
    cin>>n;
    result = n;
    if(result < 0)
        exit(0);
    else
    {
        while(result >= 8)
        {
            int temp = result % 8;
            result = result / 8;
            a[k++] = temp;
        }
        if(result != 0)
            a[k++] = result;
    
        for(int i = k-1; i >= 0;i--)
            cout<<a[i];
        cout<<endl;
    }
}
