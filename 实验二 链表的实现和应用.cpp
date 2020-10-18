/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.10.11
 最后修改时间：2020.10.18
 */

/*
 文件中定义的函数名称和主要功能：
 void  InitList(LinkList &L)    //初始化链表
 void Input(LinkList &L)     //尾插法插入结点
 void Output(LinkList L)     //输出链表数据
 int LocateElem(LinkList L,int e)   //判断L中是否有元素e
 void Union(LinkList L1,LinkList L2,LinkList &L3)    //求L1、L2并集
 void CreatePolyn(polynomial &P, int m)   //创建多项式P
 void AddPolyn(polynomial &pa,polynomial &pb)   //多项式求和
 void Print(polynomial P)   //打印多项式
 int main()   //主函数

 
 文件中定义的全局变量的变量名和主要功能：无
 文件中用到的他处定义的全局变量及其出处：无
 与其他文件的依赖关系：无
 
 所引用代码和资料出处：《数据结构（C语言版）》  ————清华大学出版社
  */


#include <iostream>
using namespace std;


typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;


typedef struct Node
{
    float coef;    //系数
    int expn;   //指数
    struct Node *next;
}Node,*polynomial;





/*
 函数名称：InitList
 函数主要功能：构造一个空链表L
 函数调用之前的预备条件：无
 函数的输入参数：LinkList &L
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void  InitList(LinkList &L)    //初始化链表
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;    //头结点
}




/*
函数名称：Input
函数主要功能：输入链表内容
函数调用之前的预备条件：无
函数的输入参数：LinkList &L
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void Input(LinkList &L)     //尾插法
{
    LinkList end = L;
    int n;
    cout<<"请输入总数:"<<endl;
    cin>>n;
    cout<<"请输入数字:"<<endl;
    for(int i = n; i > 0; i--)
    {
        LinkList node;
        node = (LinkList)malloc(sizeof(LNode));
        cin>>node->data;
        end->next = node;
        end = node;
        end->next = NULL;
    }
}


/*
函数名称：OutputList
函数主要功能：输出链表元素
函数调用之前的预备条件：无
函数的输入参数：LinkList L
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
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


/*
函数名称：LocateElem
函数主要功能：判断L中是否含有e,有返回1，没有返回0
函数调用之前的预备条件：无
函数的输入参数：LinkList L,int e
函数的输出参数：无
函数的返回值：0，1
该函数与其它函数的调用和被调用关系：被Union函数调用
*/
int LocateElem(LinkList L,int e)   //判断L3中是否有L2元素 ,有返回1，没有返回0
{
    LinkList p = L->next;
    while(p)
    {
        if(p->data == e)
            return 1;
        else
            p = p->next;
    }
    return 0;
}



/*
函数名称：Union
函数主要功能：设线性表L1和L2分别代表集合A和B，试设计算法求A和B的并集C，并用线性表L3代表集合C
函数调用之前的预备条件：无
函数的输入参数：LinkList L1,LinkList L2,LinkList &L3
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void Union(LinkList L1,LinkList L2,LinkList &L3)    //求L1、L2并集
{
    LinkList p,q,end_L3;
    p = L1->next;   //指向第一个结点
    q = L2->next;
    end_L3 = L3;    //L3尾指针
    while(p)   //把L1的值全部赋给L3
    {
        LinkList node;
        node = (LinkList)malloc(sizeof(LNode));
        node->data = p->data;
        end_L3->next = node;
        end_L3 = node;
        end_L3->next = NULL;
        p = p->next;
    }
    while (q)
    {
        if(!LocateElem(L3, q->data))    //判断L3中是否有L2元素
        {
            //没有则插入
            LinkList node;
            node = (LinkList)malloc(sizeof(LNode));
            node->data = q->data;
            end_L3->next = node;
            end_L3 = node;
            end_L3->next = NULL;
            q = q->next;
        }
        else
            q = q->next;
    }
}






/*
函数名称：CreatePolyn
函数主要功能：创建多项式P
函数调用之前的预备条件：无
函数的输入参数：polynomial &P, int m
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
//输入m项的系数和指数，建立表示一元多项式的带有头节点的有序链表P
//利用尾插法
void CreatePolyn(polynomial &P, int m)
{
    P = (polynomial)malloc(sizeof(Node));
    P->next = NULL;
    polynomial end = P;
 
    cout<<"请输入系数和指数(如5x^2输入（5 2）即可):"<<endl;
    for(int i = 0; i < m; i++)
    {
        polynomial node =(polynomial)malloc(sizeof(Node));
        cin>>node->coef>>node->expn;
        end->next = node;
        end = node;
        end->next = NULL;
    }
}



/*
函数名称：AddPolyn
函数主要功能：多项式相加
函数调用之前的预备条件：无
函数的输入参数：polynomial &pa,polynomial &pb
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void AddPolyn(polynomial &pa,polynomial &pb)   //多项式求和
{
    polynomial ha = pa->next;
    polynomial hb = pb->next;
    polynomial hc = pa;
    while(ha&&hb)
    {
        if(ha->expn < hb->expn)     //ha的指数<hb的指数
        {
            hc->next = ha;
            ha = ha->next;
            hc = hc->next;
        }
        else if(ha->expn > hb->expn)   //hb可插入
        {
            hc->next = hb;
            hb = hb->next;
            hc = hc->next;
        }
        else
        {
            ha->coef = ha->coef + hb->coef;
            if(ha->coef)   //和不为0
            {
                hc->next = ha;
                ha = ha->next;
                hc = hc->next;
                hb = hb->next;
            }
            else
            {
                polynomial p = ha;
                ha = ha->next;
                free(p);
                p = hb;
                hb = hb->next;
                free(p);
            }
        }
    }
    if(!ha)
        hc->next = hb;
    if(!hb)
        hc->next = ha;
    free(pb);
}



/*
函数名称：Print
函数主要功能：打印多项式内容
函数调用之前的预备条件：无
函数的输入参数：polynomial P
函数的输出参数：无
函数的返回值：无
该函数与其它函数的调用和被调用关系：被main函数调用
*/
void Print(polynomial P)
{
    polynomial p = P->next;
    if(p == NULL)   //多项式相加和为0时
    {
        cout<<0<<endl;
    }
    else
    {
        while (p->next)
        {
            if(p->expn == 0)
            {
                cout<<p->coef<<"+";
                p = p->next;
            }
            else if(p->expn == 1)
            {
                cout<<p->coef<<"x"<<"+";
                p = p->next;
            }
            else if(p->next->coef < 0)
            {
                cout<<p->coef<<"x^"<<p->expn;
                p = p->next;
            }
            else if(p->coef < 0)
            {
                cout<<-(p->coef)<<"x^"<<p->expn<<"-";
                p = p->next;
            }
            else
            {
                cout<<p->coef<<"x^"<<p->expn<<"+";
                p = p->next;
            }
        }
        cout<<p->coef<<"x^"<<p->expn<<endl;
    }
}



int main()
{
    cout<<"######链表求并集问题######"<<endl;
    LinkList L1,L2,L3;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    Input(L1);
    Input(L2);
    Union(L1,L2,L3);
    cout<<"合并结果:"<<endl;
    Output(L3);
    cout<<endl;
    
    cout<<"######一元多项式求和问题######"<<endl;
    polynomial Pa,Pb;
    int m1,m2;
    cout<<"请分别输入多项式1和2的总项数:"<<endl;
    cin>>m1>>m2;
    CreatePolyn(Pa, m1);
    CreatePolyn(Pb, m2);
    cout<<"第一个一元多项式为:"<<endl;
    Print(Pa);
    cout<<"第二个一元多项式为:"<<endl;
    Print(Pb);
    cout<<"相加结果为:"<<endl;
    AddPolyn(Pa, Pb);
    Print(Pa);

}
