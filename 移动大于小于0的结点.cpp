/*
 【问题描述】

 某非空单链表L中的所有元素为整数，设计一个算法将所有小于零的结点移到所有大于等于零的结点的前面。

 【输入形式】

 两行，第一行是整数个数，第二行是整数列表

 【输出形式】

 整数列表
 【样例输入】

 6

 -1 2 3 -3 -5 6

 【样例输出】

 -5 -3 -1 2 3 6

 【样例说明】

 将小于0的整数插入到头部位置
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
    L->next = NULL;    //头结点
}


void Input(LinkList &L)     //头插法 结果与实际相反
{
    int n;
    cout<<"请输入总数:"<<endl;
    cin>>n;
    cout<<"请输入数字:"<<endl;
    for(int i = n; i > 0; i--)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}



void AderseList(LinkList L1,LinkList &L2)    //继续用头插法让L2中存顺序的数值
{
    LinkList p = L1->next;  //p指向第一个结点
    while(p)
    {
        LinkList node;
        node = (LinkList)malloc(sizeof(LNode));          //  为新结点开辟新内存
        node->data = p->data;                 //新结点的数据域赋值
        node->next = L2->next;
        L2->next = node;
        p = p->next;
    }
}



void RemoveList(LinkList &L,int k)
{
    LNode *p,*q;
    p = L->next;
    q = L;
    
    if(k == 0)    //保存大于0的数，删除小于0的
    {
        while(p)
        {
            if(p->data<0)
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
    else      //保存小于0的数，删除大于0的
    {
        while(p)
        {
            if(p->data>0)
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
}



void Connect(LinkList &L1,LinkList &L2)
{
    LNode *p,*q;
    p = L1->next;
    q = L2->next;
    while(p->next)
        p = p->next;
    while(q)
    {
        LinkList node;
        node = (LinkList)malloc(sizeof(LNode));
        node->data = q->data;
        p->next = node;
        p = node;
        q = q->next;
    }
    p->next = NULL;    //不能忘记给p->next赋值 会报错
}





void Output(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}




int main()
{
    LinkList L1,L2;
    InitList(L1);
    InitList(L2);
    Input(L1);
    AderseList(L1, L2);
    RemoveList(L1,1);       //大于0 用0传递表示，小于0 用1传递表示
    RemoveList(L2, 0);
    Connect(L1, L2);
    Output(L1);
}
