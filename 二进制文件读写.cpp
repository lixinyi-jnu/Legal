/*
 【问题描述】请编写一个程序，实现如下功能

 1、定义结构体student, 包括stu_id,score 2个变量。其中stu_id是一个short型变量，score为short型变量。

 2、从键盘输入学生个数n及n个学生的数据，存储在new创建的数组a中

 3、使用write函数，以二进制形式，将a数组中存放的n个学生一次写入out.txt文件中（不要使用循环）

 4、使用read函数，以二进制形式，使用循环方式，从out.txt中每次读出一个学生信息，存储于new创建的数组b中

 5、使用write函数，以文本形式，将b数组中存放的n个学生一次写入out.txt文件中，要求添加到文件末尾（不要使用循环）

 【输入形式】

 输入第一行是整数，表示有n个学生

 输入第2到n+1行是学生信息，每行表示一个学生的stu_id,score

 【输出形式】

 输出文件名：out.txt，其中包括2次输出信息

 【输入范例】

 2

 1011 90

 1012 68

 【输出范例】

 无
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n;
    cin>>n;
    struct Student
    {
        short stu_id;
        short score;
    }stu[n];
    Student *a = new Student[n];
    Student *b = new Student[n];
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].stu_id>>stu[i].score;
        a[i].stu_id = stu[i].stu_id;
        a[i].score = stu[i].score;
    }
    
    
    ofstream oneFile("out.txt",ios::out|ios::binary);
    oneFile.write((char*)a, sizeof a);
    oneFile.close();
    
    
    ifstream twoFile("out.txt",ios::in|ios::binary);
    twoFile.read((char*)a, sizeof a);
    for(int i=0;i<n;i++)
    {
        b[i].stu_id = a[i].stu_id;
        b[i].score = a[i].score;
    }
    twoFile.close();
    
    
    ofstream threeFile("out,txt",ios::app);
    threeFile.write((char*)b, sizeof b);
    threeFile.close();
    delete []a;
    delete []b;
    return 0;
}


