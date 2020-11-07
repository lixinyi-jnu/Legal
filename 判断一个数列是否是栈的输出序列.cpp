/*
【问题描述】给出一个堆栈的输入序列，试判断一个序列是否能够由这个堆栈输出。如果能，返回总的出栈次数，如果不能，返回0。序列的输入及输出都是从左往右。（输入输出序列皆为整数且没有重复的数字，如果一个数字在输入序列中没有出现，那么其在输出序列中也不会出现）
【输入形式】第一行为输入序列的长度，第二行为输入序列的数字；第三行为输出序列的数字。输入数据以空格隔开。
【输出形式】如果是一个出栈序列，则返回总的出栈次数， 否则返回0
【样例输入】

5

1 2 3 4 5

1 2 3 4 5

【样例输出】5
【样例说明】第一行输入的是序列的长度，第一行输入的1 2 3 4 5 是输入序列，第三行是输出序列，以空格隔开，输出的总的出栈次数。
 */
#include <iostream>
#define STACK_INIT_SIZE 100   //存储空间初始分配量
#define STACKINCREMENT 10    //存储空间分配增量
using namespace std;


typedef struct
{
    int *base;
    int *top;
    int stacksize;   //当前以分配的存储空间
}SqStack;



void InitStack(SqStack &S)    //构造一个空栈
{
    S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S.base)
        exit(0);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}



int GetTop(SqStack S)
{
    return *(S.top-1);
}


void Push(SqStack &S,int e)
{
    if(S.top - S.base >= S.stacksize)   //栈满，追加存储空间
    {
        S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if(!S.base)
            exit(0);
    }
    *S.top++ = e;
}


void Pop(SqStack &S,int &e,int &result)
{
    //若栈不空，则删除S的栈顶元素，用e返回其值
    e = *--S.top;
    //S.top--;
    result++;
}



int FirstCheck(int *a,int *b,int n)  //判断输出序列是否全为输入序列的数字
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(b[i] == a[j])
                break;
            if(j == n-1 && b[i] != a[j])
                break;
        }
        if(j == n-1 && b[i] != a[j])
            break;
    }
    if(i == n)   //没有不存在的数
        return 1;
    else
        return 0;
}



void Judge(SqStack &S,int *a,int *b,int n,int &result)//输入序列是a，输出序列是b
{
    int k1 = 0, k2 = 0;
    int p = b[k1],q = a[k2];
    for(int i = 0; i < n; i++)   //在输入列中寻找输出列第一个元素 标记p、q
    {
        if(a[i] == p)
        {
            k2 = i;
            q = a[k2];
            for(int temp = 0; temp <= i; temp++)
            {
                Push(S, a[temp]);
            }
            int e;
            Pop(S,e,result);
            //cout<<e;
            k1++;
            p = b[k1];
            break;
        }
    }
    while(k1 < n && k2 < n)
    {
        //cout<<GetTop(S);
        if(GetTop(S) == p)
        {
            int e;
            Pop(S, e,result);
            //cout<<e;
            k1++;
            p = b[k1];
        }
        //else if(GetTop(S) != p)
        else
        {
            k2++;
            if(k2 == n)
            {
                result = 0;
                break;
            }
            else
            {
                q = a[k2];
                Push(S, q);
            }
        }
    }
//    if(S.top != S.base)     //如果栈不空的话 证明输出序列有误 返回0
//        result = 0;
}



int main()
{
    int result = 0;
    int n,k;
    //cout<<"请输入总数:"<<endl;
    cin>>n;
    int a[n],b[n];  //a[n]为输入序列 b[n]为输出序列
    //cout<<"请输入:"<<endl;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>b[i];
    k = FirstCheck(a, b, n);   //正常输出1，异常输出0；
    if(!k)   //输出序列有误继续
        cout<<k<<endl;
    else
    {
        SqStack S;
        InitStack(S);
        Judge(S, a, b, n, result);
        cout<<endl;
        cout<<result<<endl;
    }
}
