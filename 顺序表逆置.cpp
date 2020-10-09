/*
 【问题描述】

 设计一个高效算法，将顺序表L中的所有元素逆置，要求算法的空间复杂度为O（1）。

 【输入形式】

 两行，第一行是输入数据数量，第二行是线性表数据，元素之间用空格间隔。

 【输出形式】

 输入线性表的逆序，元素之间用空格间隔
 【样例输入】

 5

 1 2 3 4 5
 【样例输出】

 5 4 3 2 1
 【样例说明】

 输入数据是整数列，数据间以空格分开。


 */


#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的分配增量
#define Maxsize 100

typedef struct
{
    int *elem;     //存储空间基值
    int length;    //当前长度
    int listsize;  //当前分配的存储容量
}SqList;



void InitList(SqList &L)   //构造一个空的线性表L
{
    L.elem = new int[LIST_INIT_SIZE];
    if(!L.elem)
        cout<<"Failure"<<endl;   //存储失败
    L.length = 0;  //空表长度为0
    L.listsize = LIST_INIT_SIZE;   //初始存储容量
}



void InputList(SqList &L)   //输入线性表内容
{
    int n,i = 0;   //n表示总数
    cout<<"please input the total number of List:"<<endl;
    cin>>n;
    cout<< "Please input "<<n<<" numbers:"<<endl;
    while(n--)
    {
        cin>>L.elem[i];
        L.length++;
        i++;
    }
}



void Adverse(SqList &L)
{
    for(int i = 0; i < L.length/2; i++)
    {
        int temp = L.elem[i];
        L.elem[i] = L.elem[L.length-1-i];
        L.elem[L.length-1-i] = temp;
    }
}


void OutputList(SqList L)   //输出线性表元素
{
    int i;
    for(i = 0; i < L.length; i++)
        cout<<L.elem[i]<<" ";
    cout<<endl;
}


int main()
{
    SqList L;
    InitList(L);
    InputList(L);
    Adverse(L);
    OutputList(L);
}
