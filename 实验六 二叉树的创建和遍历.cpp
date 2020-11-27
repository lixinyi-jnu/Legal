//a(b(c(d,e)),f(g,h(i,j)))

/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.11.24
 最后修改时间：2020.11.27
 */

/*
 文件中定义的函数名称和主要功能
 void CreateBiTree(BiTree &T,char str[])    //用括号法创建二叉树
 void PreOrderTraverse(BiTree T)    //先序遍历二叉树
 void InOrderTraverse(BiTree T)     //中序遍历二叉树
 void PostOrderTraverse(BiTree T)   //后序遍历二叉树
 void LevelOrderTraverse(BiTree T)   //层序遍历二叉树
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
#include <stack>
#include <queue>
#define MAXSIZE 100
using namespace std;


typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

/*
 函数名称：CreateBiTree
 函数主要功能：用括号法创建二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BiTree &T,char str[]
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateBiTree(BiTree &T,char str[])    //用括号法创建二叉树
//遇到左括号就取栈顶元素加左孩子，当数字后面紧跟(时就压栈，遇到逗号就是栈顶元素的右孩子，遇到右括号就是弹栈
{
    T = NULL;
    BiTNode* p;
    stack<BiTNode *> S;
    int flag = 0,i = 0;
    while(str[i] != '\0')
    {
        switch(str[i])
        {
            case '(':flag = 1; S.push(p);break;    //左孩子flag = 1
            case ',':flag = 2;break;    //右孩子flag = 2
            case ')':S.pop();break;
            default:        //读到结点时
                p = new BiTNode;
                p->data = str[i];
                p->lchild = NULL;
                p->rchild = NULL;
                if(T == NULL)    //创建根结点
                {
                    T = p;
                }
                else
                {
                    BiTNode *temp;
                    temp = S.top();
                    switch(flag)
                    {
                        case 1:temp->lchild = p;break;
                        case 2:temp->rchild = p;break;
                    }
                }
        }
        i++;
    }
}



/*
 函数名称：PreOrderTraverse
 函数主要功能：先序遍历二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BiTree T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void PreOrderTraverse(BiTree T)    //先序遍历二叉树
{
    BiTNode *p;
    p = T;
    stack<BiTNode *> S;
    cout<<"先序遍历序列为:"<<endl;
    while(p || !S.empty())
    {
        while(p)
        {
            cout<<p->data<<" ";
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty())    //结点没有左孩子了就弹栈 找右孩子
        {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
    cout<<endl;
}



/*
 函数名称：InOrderTraverse
 函数主要功能：中序遍历二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BiTree T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void InOrderTraverse(BiTree T)     //中序遍历二叉树
{
    BiTNode *p;
    p = T;
    stack<BiTNode *> S;
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
            cout<<p->data<<" ";
            S.pop();
            p = p->rchild;
        }
    }
    cout<<endl;
}




/*
 函数名称：PostOrderTraverse
 函数主要功能：后序遍历二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BiTree T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void PostOrderTraverse(BiTree T)   //后序遍历二叉树
{
    BiTNode * p = T;
    stack<BiTNode *> S1;     //S1缓冲
    stack<BiTNode *> S2;     //S2作为输出栈
    cout<<"后序遍历序列为:"<<endl;
    while(p ||!S1.empty())
    {
        while(p)        //一直向右并将沿途节点访问（压入S2）后压入堆栈S1
        {
            S2.push(p);
            S1.push(p);
            p = p->rchild;
        }
        if (!S1.empty())
        {
            p = S1.top();
            S1.pop();    //节点弹出堆栈
            p = p->lchild;  //转向左子树
        }
    }
    while(!S2.empty())    //访问（打印）S2中元素
    {
        p = S2.top();
        S2.pop();
        cout<<p->data<<" ";
    }
    cout<<endl;
}




/*
 函数名称：LevelOrderTraverse
 函数主要功能：层序遍历二叉树
 函数调用之前的预备条件：无
 函数的输入参数：BiTree T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void LevelOrderTraverse(BiTree T)   //层序遍历二叉树
{
    BiTNode *p;
    p = T;
    queue<BiTNode *> Q;
    Q.push(p);    //根结点入队
    cout<<"层序遍历序列为:"<<endl;
    while(!Q.empty())
    {
        BiTNode *temp = Q.front();
        cout<<temp->data<<" ";
        Q.pop();      //队头结点出队并访问
        if(temp->lchild)
            Q.push(temp->lchild);
        if(temp->rchild)
            Q.push(temp->rchild);
    }
    cout<<endl;
    
}

int main()
{
    BiTree T;
    char str[MAXSIZE];
    cout<<"请输入二叉树:"<<endl;
    cin>>str;
    CreateBiTree(T, str);
    PreOrderTraverse(T);
    InOrderTraverse(T);
    PostOrderTraverse(T);
    LevelOrderTraverse(T);
}
