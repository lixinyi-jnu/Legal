/*
 快速排序
 希尔排序
 堆排序
 */

/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.12.21
 最后修改时间：2020.12.25
 */
/*
 文件中定义的函数名称和主要功能
 void swap(RecType &x,RecType &y)   //x和y交换
 void CreateList(RecType R[],int keys[],int n)   //创建顺序表
 void DispList(RecType R[],int n)   //输出顺序表
 void CreateList1(RecType R[], int keys[],int n)   //创建顺序表
 void DispList1(RecType R[],int n)     //输出顺序表
 void ShellSort(RecType R[],int n)    //希尔排序
 void disppart(RecType R[],int s,int t)  //显示一趟划分后的结果
 int partition(RecType R[],int s,int t)   //一趟划分
 void QuickSort(RecType R[],int s,int t)    //快速排序   s是开始位置 t是结束位置
 void DispHeap(RecType R[],int i,int n)   //以括号表示法输出建立的堆
 void Sift(RecType R[],int low, int high)   //R[low...high]堆筛选算法
 void HeapSort(RecType R[],int n)  //对R[1]到R[n]元素实现堆排序
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
#include <iomanip>
#include <time.h>
using namespace std;
#define MAXL 100
int Count = 1;   //全局变量，累计排序趟数


typedef struct
{
    int key;      //关键字项
    char data;    //其他数据项
}RecType;         //查找元素的类型


/*
 函数名称：swap
 函数主要功能：x和y交换
 函数调用之前的预备条件：无
 函数的输入参数：RecType &x,RecType &y
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被HeapSort函数调用
 */
void swap(RecType &x,RecType &y)   //x和y交换
{
    RecType tmp = x;
    x = y;
    y = tmp;
}


/*
 函数名称：CreateList
 函数主要功能：创建顺序表
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int keys[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateList(RecType R[],int keys[],int n)   //创建顺序表
{
    for(int i = 0; i < n; i++)   //R[0...n-1]
        R[i].key = keys[i];
}

void DispList(RecType R[],int n)   //输出顺序表
{
    for(int i = 0; i < n; i++)
        cout<<R[i].key<<" ";
    cout<<endl;
}



/*
 函数名称：CreateList1
 函数主要功能：创建顺序表
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int keys[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
//堆排序的操作
void CreateList1(RecType R[], int keys[],int n)   //创建顺序表
{
    for(int i = 0; i <= n; i++)   //R[1...n]
        R[i].key = keys[i-1];
}

/*
 函数名称：DispList1
 函数主要功能：输出顺序表
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void DispList1(RecType R[],int n)     //输出顺序表
{
    for(int i = 1; i <= n; i++)
        cout<<R[i].key<<" ";
    cout<<endl;
}


/*
 函数名称：ShellSort
 函数主要功能：希尔排序
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void ShellSort(RecType R[],int n)    //希尔排序
{
    cout<<"希尔排序过程:"<<endl;
    int i,j,d;    //d是增量
    RecType tmp;
    d = n/2;
    while(d > 0)
    {
        for(i = d; i < n; i++)   //对相隔d个位置一组采用直接插入排序
        {
            tmp = R[i];    //tmp存临时值
            j = i - d;
            while(j >= 0 && tmp.key < R[j].key)
            {
                R[j+d] = R[j];
                j = j - d;
            }
            R[j+d] = tmp;
        }
        cout<<"d="<<d<<" ";
        DispList(R, n);
        d = d/2;    //减小增量
    }
}

/*
 函数名称：disppart
 函数主要功能：显示一趟划分后的结果
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int s,int t
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被partition函数调用
 */
void disppart(RecType R[],int s,int t)  //显示一趟划分后的结果
{
    static int i = 1;
    int j;
    cout<<"第"<<i<<"次划分:";
    for(j = 0; j < s ; j++)
    cout<<"  ";
    for( j = s; j <= t; j++)
    cout<<setw(3)<<R[j].key;
    cout<<endl;
    i++;
}



/*
 函数名称：partition
 函数主要功能：一趟划分
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int s,int t
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被QuickSort函数调用
 */
int partition(RecType R[],int s,int t)   //一趟划分
{
    int i = s,j = t;
    RecType tmp = R[i];    //以R[i]为基准
    while(i < j)
    {
        while (j > i && R[j].key >= tmp.key)    //右侧的h指针
            j--;
        R[i] = R[j];
        while(i < j && R[i].key <= tmp.key)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    disppart(R, s, t);
    return i;
}


/*
 函数名称：QuickSort
 函数主要功能：快速排序
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int s,int t
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void QuickSort(RecType R[],int s,int t)    //快速排序   s是开始位置 t是结束位置
{
    int i;
    if(s<t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i-1);    //对左区间递归排序
        QuickSort(R, i+1, t);    //对右区间递归排序
    }
}


/*
 函数名称：DispHeap
 函数主要功能：以括号表示法输出建立的堆
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int s,int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void DispHeap(RecType R[],int i,int n)   //以括号表示法输出建立的堆
{
    if(i <= n)
        cout<<R[i].key;    //根结点
    if(2 * i <= n || 2*i+1 < n)
    {
        cout<<"(";
        if(2*i <= n)
            DispHeap(R, 2*i, n);    //递归调用输出左子树
        cout<<",";
        if(2*i+1 <= n)
            DispHeap(R, 2*i+1, n);    //递归调用输出右子树
        cout<<")";
    }
}



/*
 函数名称：Sift
 函数主要功能：R[low...high]堆筛选算法
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int low, int high
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Sift(RecType R[],int low, int high)   //R[low...high]堆筛选算法
{
    int i = low,j=2*i;     //R[j]是R[i]的左孩子
    RecType temp = R[i];
    while (j <= high)
    {
        if(j < high && R[j].key < R[j+1].key)   //若右孩子较大，把j指向右孩子
            j++;
        if(temp.key < R[j].key)
        {
            R[i] = R[j];     //将R[j]调整到双亲结点位置上
            i = j;
            j = 2*i;
        }
        else
            break;  //筛选结束
    }
    R[i] = temp;
}


/*
 函数名称：HeapSort
 函数主要功能：对R[1]到R[n]元素实现堆排序
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void HeapSort(RecType R[],int n)  //对R[1]到R[n]元素实现堆排序
{
    int i,j;
    for(i = n/2; i >= 1; i--)    //循环建立初始堆
    Sift(R, i, n);
    cout<<"初始堆:";
    DispHeap(R, 1, n);
    cout<<endl;
    for(i = n; i >= 2; i--)
    {
        cout<<"第"<<Count++<<"趟排序:";
        cout<<"交换"<<R[i].key<<"与"<<R[1].key<<",输出"<<R[1].key;
        swap(R[1],R[i]);
        cout<<"排序结果:";
        for(j = 1; j <= n; j++)
        cout<<setw(2)<<R[j].key<<" ";
        cout<<endl;
        Sift(R, 1, i-1);
        cout<<"筛选调整得到堆:";
        DispHeap(R, 1, i-1);
        cout<<endl;
    }
}


int main()
{
    int n;
    cout<<"请输入产生随机数个数:"<<endl;
    cin>>n;
    int a[n];
    srand((int)time(0));    //产生随机种子
    for(int i = 0; i < n; i++)
    {
        int m = rand()%100;
        a[i] = m;
    }
    RecType R[MAXL];
    CreateList(R, a, n);
    cout<<"待排序数字:"<<endl;
    DispList(R, n);
    cout<<endl;
    
    ShellSort(R, n);
    cout<<"希尔排序结果:";
    DispList(R, n);
    cout<<endl;
    
    CreateList(R, a, n);
    cout<<"快速排序过程:"<<endl;
    QuickSort(R, 0, n-1);
    cout<<"快速排序结果:";
    DispList(R, n);
    cout<<endl;
    
    
    CreateList1(R, a, n);
    cout<<"堆排序过程:"<<endl;
    HeapSort(R, n);
    cout<<"堆排序结果:";
    DispList1(R, n);
}
