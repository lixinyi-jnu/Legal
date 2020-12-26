/*
 折半查找
 二叉排序树
 分块查找 
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
 void CreateList(RecType R[],int keys[],int n)     //创建顺序表
 void DispList(RecType R[],int n)   //输出顺序表
 int BinSearch(RecType R[],int n,int k)    //折半查找算法
 bool InsertBST(BSTNode *&bt, int k)   //以bt为根结点的BST中插入一个关键字为k的结点
 void DispBST(BSTNode *bt)    //输出二叉排序树
 BSTNode * CreateBST(int A[],int n)   //建立二叉排序树
 void SearchBST(BSTNode *bt, int k,int path[],int i)  //二叉树查找
 void InOrderTraverse(BSTNode *T)     //中序遍历二叉树
 int IdxSearch(IdxType I[],int b,RecType R[],int n,int k)   //分块查找
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
#include <stack>
using namespace std;
#define MAXL 100    //顺序表的长度

typedef struct
{
    int key;      //关键字项
    char data;    //其他数据项
}RecType;     //查找顺序表元素类型


/*
 函数名称：CreateList
 函数主要功能：创建顺序表
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int keys[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateList(RecType R[],int keys[],int n)     //创建顺序表
{
    for(int i = 0; i < n; i++)      //R[0...n-1]存放排序记录
    R[i].key = keys[i];
}


/*
 函数名称：DispList
 函数主要功能：输出顺序表
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void DispList(RecType R[],int n)   //输出顺序表
{
    for(int i = 0; i < n; i++)
    cout<<R[i].key<<" ";
    cout<<endl;
}


/*
 函数名称：BinSearch
 函数主要功能：折半查找算法
 函数调用之前的预备条件：无
 函数的输入参数：RecType R[],int n,int k
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
int BinSearch(RecType R[],int n,int k)    //折半查找算法
{
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(R[mid].key == k)     //查找成功返回
            return mid+1;
        if(R[mid].key > k)     //继续在R[low...mid-1]中查找
            high = mid - 1;
        else
            low = mid + 1;    //继续R[mid+1...high]中查找
    }
    return 0;
}


//二叉排序树的结构体定义
typedef struct node
{
    int key;    //关键字项
    char data;   //其他数据项
    struct node * lchild,*rchild;   //左右孩子指针
}BSTNode;


/*
 函数名称：InsertBST
 函数主要功能：以bt为根结点的BST中插入一个关键字为k的结点
 函数调用之前的预备条件：无
 函数的输入参数：BSTNode *&bt, int k
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
bool InsertBST(BSTNode *&bt, int k)   //以bt为根结点的BST中插入一个关键字为k的结点
{
    if(bt == NULL)
    {
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt -> key = k;
        bt -> lchild = bt->rchild = NULL;
        return true;
    }
    else if(k == bt->key)
        return false;
    else if(k < bt->key)
        return InsertBST(bt->lchild, k);     //值小插入到左子树
    else
        return InsertBST(bt->rchild, k);     //值大插入到右子树
}


/*
 函数名称：DispBST
 函数主要功能：输出二叉排序树
 函数调用之前的预备条件：无
 函数的输入参数：BSTNode *b
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void DispBST(BSTNode *bt)    //输出二叉排序树
{
    if(bt != NULL)
    {
        cout<<bt->key;
        if(bt -> lchild!= NULL || bt->rchild != NULL)
        {
            cout<<"(";
            DispBST(bt->lchild);
            if(bt->rchild != NULL)
                cout<<",";
            DispBST(bt->rchild);
            cout<<")";
        }
    }
}



/*
 函数名称：CreateBST
 函数主要功能：输出二叉排序树
 函数调用之前的预备条件：无
 函数的输入参数：int A[],int n
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
BSTNode * CreateBST(int A[],int n)   //建立二叉排序树
{
    BSTNode * bt = NULL;
    int i = 0;
    while(i < n)
    {
        if(InsertBST(bt, A[i]) == 1)    //将A[i]插入到二叉排序树中
        {
            cout<<"插入:"<<A[i]<<":";
            DispBST(bt);
            cout<<endl;
            i++;
        }
    }
    return bt;
}


/*
 函数名称：SearchBST
 函数主要功能：二叉树查找
 函数调用之前的预备条件：无
 函数的输入参数：BSTNode *bt, int k,int path[],int i
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void SearchBST(BSTNode *bt, int k,int path[],int i)  //二叉树查找
{
    int j;
    if(bt == NULL)
        return;
    else if( k == bt->key )
    {
        path[i+1] = bt->key;
        for(j = 0; j <= i + 1; j++)
        cout<<setw(3)<<path[j];
        cout<<endl;
    }
    else
    {
        path[i+1] = bt->key;
        if(k < bt->key)
            SearchBST(bt->lchild, k, path, i+1);     //在左子树递归
        else
            SearchBST(bt->rchild, k, path, i+1);    //在右子树递归
    }
}


/*
 函数名称：InOrderTraverse
 函数主要功能：中序遍历二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BSTNode *T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void InOrderTraverse(BSTNode *T)     //中序遍历二叉树
{
    BSTNode *p;
    p = T;
    stack<BSTNode *> S;
    cout<<"中序遍历序列为:"<<endl;
    while(p || !S.empty())
    {
        while(p)
        {
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty())
        {
            p = S.top();
            cout<<p->key<<" ";
            S.pop();
            p = p->rchild;
        }
    }
    cout<<endl;
}


//分块查找的结构体定义
typedef struct
{
    int key;
    int link;    //指向分块的起始下标
}IdxType;      //索引表元素类型


/*
 函数名称：IdxSearch
 函数主要功能：分块查找
 函数调用之前的预备条件：无
 函数的输入参数：IdxType I[],int b,RecType R[],int n,int k
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
int IdxSearch(IdxType I[],int b,RecType R[],int n,int k)   //分块查找
{
    int s = (n+b-1)/b;
    int count1 = 0, count2 = 0;
    int low = 0, high = b-1,mid,i;
    while( low <= high)
    {
        mid = (high + low)/2;
        cout<<"第"<<count1+1<<"次比较元素"<<R[mid].key<<endl;
        if(I[mid].key >= k)
            high = mid - 1;
        else
            low = mid + 1;
        count1++;
    }
    cout<<"比较"<<count1<<"次"<<",在第"<<low<<"块中查找元素"<<k<<endl;
    i = I[high + 1].link;
    cout<<"在对应块中顺序查找:"<<endl;
    while(i <= I[high + 1].link + s -1)
    {
        cout<<setw(3)<<R[i].key;
        count2++;
        if(R[i].key == k)
            break;
        i++;
    }
    cout<<"比较"<<count2<<"次，查找"<<k<<endl;
    if(i <= I[high+1].link+s-1)
        return i+1;      //查找成功，返回该元素的逻辑序号
    else
        return 0;       //查找失败，返回0
}

int main()
{
    cout<<"###折半查找###"<<endl;
    RecType R[MAXL];
    int k1,n1,i;    //  k1是要查找的数
    cout<<"请输入产生随机数个数:"<<endl;
    cin>>n1;
    int a1[n1];
    srand((int)time(0));    //产生随机种子
    for(i = 0; i < n1; i++)
    {
        int m = rand()%100;
        a1[i] = m;
    }
    
    for(i = 0; i < n1; i++)
    {
        for(int j = 0; j < n1-i; j++)
        {
            if (a1[j]>a1[j+1])
            {
                int s = a1[j];
                a1[j] = a1[j+1];
                a1[j+1] = s;
            }
        }
    }
    
    CreateList(R, a1, n1);      //建立顺序表
    cout<<"关键字序列:";
    DispList(R, n1);
    cout<<"请输入要查找的数字:"<<endl;
    cin>>k1;
    if((i = BinSearch(R, n1, k1)) != -1)  //指导low比high小就停止查找
        cout<<"元素"<<k1<<"的位置是:"<<i<<endl;
    else
        cout<<"无该元素"<<endl;
    
    
    
    //分块排序
    cout<<endl;
    cout<<"###分块查找###"<<endl;
    IdxType I[MAXL];
    int n2 = 25;
    int a2[] = {8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
    CreateList(R, a2, n2);
    I[0].key = 14;I[0].link = 0;
    I[1].key = 34;I[1].link = 4;
    I[2].key = 66;I[2].link = 10;
    I[3].key = 85;I[3].link = 15;
    I[4].key = 100;I[4].link = 20;
    cout<<"关键词序列:";
    for(i = 0; i < n2; i++)
    cout<<R[i].key<<" ";
    cout<<endl;
    
    int k2;
    cout<<"请输入查找元素:"<<endl;
    cin>>k2;
    if((i = IdxSearch(I, 5, R, 25, k2)) != -1)
        cout<<"元素"<<k2<<"的位置是"<<i<<endl;
    else
        cout<<"元素"<<k2<<"不在表中"<<endl;
    
    
    //二叉查找树
    cout<<endl;
    cout<<"###二叉查找树###"<<endl;
    BSTNode *bt;
    int k3,n3;
    int path[100];
    cout<<"请输入产生随机数个数:"<<endl;
    cin>>n3;
    int a3[n3];
    srand((int)time(0));    //产生随机种子
    for(i = 0; i < n3; i++)
    {
        int m = rand()%100;
        a3[i] = m;
    }
    cout<<"随机数为:";
    for(i = 0; i < n3; i++)
    cout<<a3[i]<<" ";
    
    cout<<"创建一颗BST树:"<<endl;
    bt = CreateBST(a3,n3);
    cout<<"请输入查找元素:"<<endl;
    cin>>k3;
    cout<<"查找过程:"<<endl;
    SearchBST(bt, k3,path,-1);
    InOrderTraverse(bt);
    
}
