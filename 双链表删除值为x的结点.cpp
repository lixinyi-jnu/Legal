/*
 【问题描述】

 有一个非空双链表L，设计一个算法删除所有值为x的结点。

 【输入形式】

 输入数据为两行，第一行是输入数据个数，第二行是输入数据，第三行是x的值
 【输出形式】

 删除值为x后的序列，以空格分隔
 【样例输入】

 7

 1 3 5 6 8 6 7

 6
 【样例输出】

 1 3 5 8 7
 */


#include <iostream>
using namespace std;

typedef struct DuLNode
{
    int data;
    struct DuLNode *next;
    struct DuLNode *pre;
}DuLNode,*DuLinkList;


void create_tail_DLinklist(DuLinkList &head)//采用尾插法构建双链表
{
    head = (DuLinkList)malloc(sizeof(DuLNode) );
    head->pre= NULL ;
    head->next = NULL ;//创建头结点

    DuLinkList p = head;  // 指向头结点
    int n;
    cin>>n;

    while(n--)
    {
        DuLinkList q = (DuLinkList)malloc(sizeof(DuLNode));
        cin>>q->data;
        q->next = NULL ;

        q->pre = p;
        p->next = q ;
        p = q ;
    }
}




void DeleteList(DuLinkList &head,int k)
{
    DuLinkList p = head->next;
    while(p)
    {
        if(p->data == k)
        {
            DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
            temp = p;
            p->pre->next = p->next;
            p->next->pre = p->pre;
            p = p->next;
            free(temp);
        }
        else
            p = p->next;
    }
}



void Output(DuLinkList head)
{
    DuLinkList p = head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}




int main()
{
    DuLinkList head;
    int k;
    create_tail_DLinklist(head);
    cin>>k;
    DeleteList(head,k);
    Output(head);
}





