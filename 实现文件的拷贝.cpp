/*
 【问题描述】请编写一个程序，实现如下功能

 a.txt文件中已经预先存储了一组数据，以空格分隔，数据的个数不确定。

 从a.txt文件中读取数据，并将从小到大排序后的数据输出到b.txt文件

 b.txt文件中数据以空格分隔
 【输入形式】

 输入文件名：a.txt
 【输出形式】

 输出文件名：b.txt
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int i,j;
    double k;
    vector<double>a;
    ifstream oneFile("a.txt",ios::in);
    if(oneFile)
    {
        while(oneFile.good())
        {
            oneFile>>k;
            a.push_back(k);
        }
    }
    else
    {
        cout<<"ERROR:Cannot open file."<<endl;
    }
    oneFile.close();
    for(i = 0;i<a.size()-1;i++)
        for(j=0;j<a.size()-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                double temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    ofstream twoFile("b.txt",ios::out);
    for(vector<double>::iterator it=a.begin();it!=a.end();it++)
        twoFile<<*it<<" ";
    twoFile.close();
}

