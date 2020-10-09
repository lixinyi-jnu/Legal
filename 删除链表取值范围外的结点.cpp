/*
 【问题描述】

 设计一个算法，删除带头结点的单链表L中data值大于或等于min、小于或等于max之间的结点（若表中有这样的结点），同时释放被删除结点的空间，这里min和max是两个给定的参数

 【输入形式】

 输入共三行，第一行是数据个数，第二行是输入数据，第三行是最小值min和最大值max，数据之间以空格分开
 【输出形式】

 删除后的线性表
 【样例输入】

 5

 1 2 3 4 5

 1 4
 【样例输出】

 5
 */

#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;



void  InitList(LinkList &L)    //初始化链表
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
}


void Input(LinkList &L)
{
    int n;
    cin>>n;
    for(int i = n; i > 0; i--)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}


void ListDelete(LinkList &L,int min,int max)
{
    LNode *p,*q;
    p = L->next;
    q = L;
    while(p)
    {
        if(p->data>=min && p->data<=max)
        {
            LNode *temp = p;
            q->next = p->next;
            p = p->next;
            free(temp);
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}


void Output(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}





int main()
{
    LinkList L;
    InitList(L);
    Input(L);
    int min,max;
    cin>>min>>max;
    ListDelete(L,min,max);
    Output(L);
}

