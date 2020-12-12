/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.12.3
 最后修改时间：2020.12.4
 */
/*
 文件中定义的函数名称和主要功能
 void CreateHT(HTNode ht[],int n)    //构造n个叶子结点的赫夫曼树
 void CreateHCode(HTNode ht[],HCode hcd[],int n)    //构造赫夫曼编码
 void Output(HTNode ht[],HCode hcd[],int n)    //输出赫夫曼编码
 void SolveHT(HTNode ht[],HCode hcd[],int n)     //解码
 void TransHT(HTNode ht[],HCode hcd[],int n)     //译码
 int main()   //主函数
 */
/*
 文件中定义的全局变量的变量名和主要功能：无
 文件中用到的他处定义的全局变量及其出处：无
 与其他文件的依赖关系：无
 */

/*
 所引用代码和资料出处：
 《数据结构（C语言版）》  ————清华大学出版社
 
 */



#include <iostream>
#include <string.h>
#define N 50     //叶子结点数
#define M 2*N-1  //总结点数    赫夫曼树中总结点数 = 2*叶子结点-1
using namespace std;

typedef struct {
    char data;
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode;      //结点定义


typedef struct {
    char cd[N];      //存放赫夫曼编码
    int start;       //开始指针 记录每个字母编码在cd数组里开始的位置
}HCode;     //赫夫曼编码

/*
 函数名称：CreateHT
 函数主要功能：//构造n个叶子结点的赫夫曼树
 函数调用之前的预备条件：无
 函数的输入参数：HTNode ht[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateHT(HTNode ht[],int n)    //构造n个叶子结点的赫夫曼树
{
    int i,k,lnode,rnode;
    int min1,min2;    //存放最小的两个结点
    for(i = 0; i < 2*n-1; i++)      //将所有结点的双亲指针置为NULL
    {
        ht[i].parent = -1;
        ht[i].lchild = -1;
        ht[i].rchild = -1;
    }

    for(i = n; i < 2*n-1; i++)
    {
        min1 = min2 = 32767;     //每次循环时都将min初始化
        lnode = -1;     //lnode存最小的，rnode存次小的
        rnode = -1;
        for(k = 0; k <= i-1; k++) //遍历现在存在的i个结点
        {
            if(ht[k].parent == -1)   //没有父母结点的才判断
            {
                if(ht[k].weight < min1)
                {
                    min2 = min1;
                    rnode = lnode;   //有比min1还小的，原min1就变成了次小的，赋给min2
                    min1 = ht[k].weight;
                    lnode = k;
                }
                else if(ht[k].weight < min2)
                {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
            ht[lnode].parent = i;
            ht[rnode].parent = i;
            ht[i].weight = ht[lnode].weight + ht[rnode].weight;
            ht[i].lchild = lnode;
            ht[i].rchild = rnode;
    }
}

/*
 函数名称：CreateHCode
 函数主要功能：构造赫夫曼编码
 函数调用之前的预备条件：无
 函数的输入参数：HTNode ht[],HCode hcd[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateHCode(HTNode ht[],HCode hcd[],int n)    //构造赫夫曼编码
{
    int i,f,c;
    HCode hc;
    for(i = 0; i < n; i++)
    {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        while (f!= -1)
        {
            if(ht[f].lchild == c)
                hc.cd[hc.start--] = '0';
            else
                hc.cd[hc.start--] = '1';
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}

/*
 函数名称：Output
 函数主要功能：输出赫夫曼编码
 函数调用之前的预备条件：无
 函数的输入参数：HTNode ht[],HCode hcd[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Output(HTNode ht[],HCode hcd[],int n)    //输出赫夫曼编码
{
    int i,j;
    cout<<"字符赫夫曼编码如下:"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<<ht[i].data<<":";
        for(j = hcd[i].start; j <= n; j++)
        cout<<hcd[i].cd[j];
        cout<<endl;
    }
}

/*
 函数名称：SolveHT
 函数主要功能：解码
 函数调用之前的预备条件：无
 函数的输入参数：HTNode ht[],HCode hcd[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void SolveHT(HTNode ht[],HCode hcd[],int n)     //解码
{
    cout<<"请输入待解码的字符串:"<<endl;
    string exp;    //待解码的字符串
    cin>>exp;
    cout<<"解码为:";
    for(int i = 0; i < exp.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(exp[i] == ht[j].data)     //字符相等
            {
                for(int m = hcd[j].start; m <= n; m++)   //输出相应编码
                cout<<hcd[j].cd[m];
            }
        }
    }
    cout<<endl;
}

/*
 函数名称：TransHT
 函数主要功能：译码
 函数调用之前的预备条件：无
 函数的输入参数：HTNode ht[],HCode hcd[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void TransHT(HTNode ht[],HCode hcd[],int n)     //译码
{
    cout<<"请输入待编码的字符串:"<<endl;
    string exp;
    int i = 0;
    cin>>exp;
    int node = 2*n-2;
    while(exp[i] != '\0')
    {
        if(exp[i] == '0')    //左孩子
            node = ht[node].lchild;
        else if(exp[i] == '1')
            node = ht[node].rchild;
        
        if(ht[node].lchild == -1)
        {
            cout<<ht[node].data;
            node = 2*n-2;
        }
        i++;
    }
    
    cout<<endl;
}


int main()
{
    int n;
    cout<<"请输入结点个数:"<<endl;
    cin>>n;
    HTNode ht[2*n-1];   //赫夫曼树=>赫夫曼树中总结点数 = 2*叶子结点-1
    HCode hcd[n];   //n个结点的赫夫曼编码

    cout<<"请输入各个结点的内容:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>ht[i].data;
    }
    cout<<"请输入各个结点的权重:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>ht[i].weight;
    }
    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
    Output(ht, hcd, n);
    SolveHT(ht, hcd, n);
    TransHT(ht, hcd, n);
}
