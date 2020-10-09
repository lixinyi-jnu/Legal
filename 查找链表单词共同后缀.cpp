/*
 【问题描述】假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时可共享相同的后缀存储空间，例如“loading”和”being”
 【输入形式】

 输入共三行，第一行为两个单词长度，第二行为第一个单词，第三行为第二个单词

 【输出形式】

 两个单词共同后缀
 【样例输入】

 7 5

 loading

 being
 【样例输出】

 ing
 */


#include <iostream>
using namespace std;


typedef struct LNode
{
    char data;
    struct LNode *next;
}LNode,*LinkList;



void  InitList(LinkList &L,int k)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(int i = k; i > 0; i--)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}



void Search(LinkList L1,LinkList L2,LinkList &L3)
{
    LNode *p,*q;
    int len = 0;
    p = L1->next;
    q = L2->next;
    while(p&&q)
    {
        if(p->data != q->data)
        {
            p = L1->next;
            break;
        }
        else
        {
            p = p->next;
            q = q->next;
            len++;
        }
    }
    L3 = (LinkList)malloc(sizeof(LNode));
    L3->next = NULL;
    while(len--)
    {
        LinkList a;
        a = (LinkList)malloc(sizeof(LNode));
        a->data = p->data;
        a->next = L3->next;
        L3->next = a;
        p = p->next;
    }
}



void Output(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        cout<<p->data;
        p = p->next;
    }
}


int main()
{
    LinkList str1,str2,str3;
    int len1,len2;
    cout<<"请输入两个单词长度:"<<endl;
    cin>>len1>>len2;
    InitList(str1,len1);
    InitList(str2,len2);
    Search(str1, str2, str3);
    Output(str3);
}
