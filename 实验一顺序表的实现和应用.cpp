/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.9.15
 最后修改时间：2020.9.18
 */


/*
 文件中定义的函数名称和主要功能
 void InitList(SqList &L)   //构造一个空的线性表L
 int ListLength(SqList L)     //返回L中数据元素个数
 void GetElem(SqList L,int i,int &e)   //用e返回L中的第i个数据元素的值
 int LocateElem(SqList L,int e)   //判断a中是否含有e ,有返回1，没有返回0
 int LocateElem(SqList L,int e)   //判断a中是否含有e ,有返回1，没有返回0
 void ListInsert(SqList &L,int i,int e)   //在第i个位置之前插入新元素e
 void InputList(SqList &L)   //输入线性表内容
 void OutputList(SqList L)   //输出线性表元素
 void Union(SqList L1,SqList L2,SqList &L3)   //合并
 void Delete(SqList L)     //释放elem的空间
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




/*
 函数名称：InitList
 函数主要功能：构造一个空的线性表L
 函数调用之前的预备条件：无
 函数的输入参数：SqList &L
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void InitList(SqList &L)   //构造一个空的线性表L
{
    L.elem = new int[LIST_INIT_SIZE];
    if(!L.elem)
        cout<<"Failure"<<endl;   //存储失败
    L.length = 0;  //空表长度为0
    L.listsize = LIST_INIT_SIZE;   //初始存储容量
}




/*
函数名称：ListLength
函数主要功能：返回L中数据元素个数
函数调用之前的预备条件：无
函数的输入参数：SqList L
函数的输出参数：无
函数的返回值：线性表的长度
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
int ListLength(SqList L)     //返回L中数据元素个数
{
    return L.length;
}





/*
函数名称：GetElem
函数主要功能：用e返回L中的第i个数据元素的值
函数调用之前的预备条件：无
函数的输入参数：SqList L,int i,int &e
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
void GetElem(SqList L,int i,int &e)   //用e返回L中的第i个数据元素的值 下标-1
{
    e = L.elem[i-1];
}






/*
函数名称：LocateElem
函数主要功能：判断a中是否含有e ,有返回1，没有返回0
函数调用之前的预备条件：无
函数的输入参数：SqList L,int e
函数的输出参数：无
函数的返回值：0，1
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
int LocateElem(SqList L,int e)   //判断a中是否含有e ,有返回1，没有返回0
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e)
            return 1;
    }
    return 0;
}






/*
函数名称：ListInsert
函数主要功能：在第i个位置之前插入新元素e
函数调用之前的预备条件：无
函数的输入参数：SqList &L,int i,int e
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
void ListInsert(SqList &L,int i,int e)   //在第i个位置之前插入新元素e
{
    int k;
    for( k = L.length-1; k>= i-1; k--)    //插入位置后数据元素向后移动一位
        L.elem[k+1] = L.elem[k];

    L.elem[i-1] = e;
    L.length++;
}






/*
函数名称：InputList
函数主要功能：输入线性表内容
函数调用之前的预备条件：无
函数的输入参数：SqList &L
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
void InputList(SqList &L)   //输入线性表内容
{
    int n,i = 0;   //n表示总数
    cout<<"please input the total number of List:"<<endl;
    cin>>n;
    while(n>L.listsize)
    {
        int * newbase;
        newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT) *sizeof(int));
        //realloc更改已经配置的内存空间
        if(!newbase)
            exit(0);
        L.elem = newbase;   //*elem就是新的空间大小了
        L.listsize += LISTINCREMENT;

    }
    
    cout<< "Please input "<<n<<" numbers:"<<endl;
    while(n--)
    {
        cin>>L.elem[i];
        L.length++;
        i++;
    }
}




/*
函数名称：OutputList
函数主要功能：输出线性表元素
函数调用之前的预备条件：无
函数的输入参数：SqList L
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void OutputList(SqList L)   //输出线性表元素
{
    int i;
    for(i = 0; i < L.length; i++)
        cout<<L.elem[i]<<" ";
    cout<<endl;
}





/*
函数名称：Union
函数主要功能：设线性表L1和L2分别代表集合A和B，试设计算法求A和B的并集C，并用线性表L3代表集合C
函数调用之前的预备条件：无
函数的输入参数：SqList L1,SqList L2,SqList &L3
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void Union(SqList L1,SqList L2,SqList &L3)   //合并
{
    int L1_len,L2_len,L3_len,i,e;
    L1_len = ListLength(L1);
    L2_len = ListLength(L2);
    for(i = 0; i < L1_len; i++)    //把L1的值全部赋到L3里
    {
        L3.elem[i] = L1.elem[i];
        L3.length++;
    }
    L3_len = ListLength(L3);
    for(i = 1; i <= L2_len; i++)    //线性表从1开始 GetELem中下标-1
    {
        GetElem(L2, i, e);   //取L2中第i个数据元素赋值给e
        if(!LocateElem(L3, e))   //判断L3中是否含有e ,有返回1，没有返回0
            ListInsert(L3, ++L3_len, e);   //L3中不存在与e相同的元素 则插入L3中

    }
}




/*
函数名称：Delete
函数主要功能：释放elem的空间
函数调用之前的预备条件：无
函数的输入参数：SqList L
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void Delete(SqList L)     //释放elem的空间
{
    delete L.elem;
}





int main()
{
    SqList L1,L2,L3;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    InputList(L1);
    InputList(L2);
    Union(L1,L2,L3);
    cout <<"After combining the result is:"<<endl;
    OutputList(L3);
    Delete(L1);
    Delete(L2);
    Delete(L3);
}




