/*
 5 10
0 13 32767 4 32767
13 0 15 32767  5
32767  32767 0 12 32767
4 32767 12 0 32767
32767 32767 6 3 0
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define INF 32767   //定义无穷
#define MAXV 100    //最大顶点个数
int visited[MAXV];   //全局数组

//邻接矩阵类型
typedef struct
{
    int no;       //顶点编号
    char info;   //顶点其他信息
}VertexType;    //顶点类型


typedef struct
{
    int edges[MAXV][MAXV];      //邻接矩阵数组
    int n,e;       //顶点数和边数
    VertexType vexs[MAXV];    //存放顶点信息
}MatGraph;   //邻接矩阵类型



//邻接表类型
typedef struct ANode
{
    int adjvex;   //该弧所指向的顶点的位置
    struct ANode * nextarc;    //指向下一条边的指针
    int weight;    //权重
}ArcNode;   //边结点类型

typedef struct Vnode
{
    //char info;    //顶点信息
    ArcNode *firstarc;   //指向第一条边
}VNode;    //邻接表头结点类型

typedef struct
{
    VNode adjlist[MAXV];     //邻接边头结点数组
    int n,e;    //图中顶点数n和边树e
}AdjGraph;     //邻接表类型


//✅邻接矩阵的实现
void CreateGraph(MatGraph &G,int n,int e,int A[MAXV][MAXV])   //创建邻接矩阵
{
    G.e = e;
    G.n = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        G.edges[i][j] = A[i][j];
    }
}

void DispGraph(MatGraph &G)     //输出邻接矩阵
{
    cout<<"图的邻接矩阵为:"<<endl;
    for(int i = 0; i < G.n; i++)
    {
        for(int j = 0; j < G.n; j++)
        {
            if(G.edges[i][j]!=INF)
                //printf("%3d",G.edges[i][j]);
                cout<<setw(3)<<G.edges[i][j];
            else
                //printf("%5s","∞");
                cout<<setw(5)<<"∞";
        }
        cout<<endl;
    }
}

void DeleGraph_v(MatGraph G)        //邻接矩阵结点v的删除
{
    int v;
    cout<<"请输入删除结点:"<<endl;
    cin>>v;
    MatGraph M;
    int delete_e = 0;
    M.n = G.n - 1;      //新矩阵结点-1
    for(int i = 0; i < G.n; i++)       //遍历计算从结点v出去/进来的边数
    {
        for(int j = 0; j < G.n; j++)
        {
            if(i == v || j == v)
                if(G.edges[i][j] != INF && G.edges[i][j] != 0)
                    delete_e ++;
        }
    }
    M.e = G.e - delete_e;    //新的边数
    
    int row = 0, col = 0;
    for(int i = 0; i < G.n; i++)      //得到删除结点后的邻接矩阵
    {
        if(i == v)
            continue;
        else
        {
            col = 0;
            for(int j = 0; j < G.n; j++)
            {
                if(j== v)
                    continue;
                else
                {
                    M.edges[row][col] = G.edges[i][j];
                    col ++;
                }
            }
        }
        row ++;
    }
    cout<<"邻接矩阵删除结点新";
    DispGraph(M);
}


void DeleGraph_e(MatGraph G)        //邻接矩阵边e的删除
{
    int front,rear;
    cout<<"请输入删除边的头、尾结点:"<<endl;
    cin>>front>>rear;
    MatGraph M;
    M.e = G.e - 1;
    M.n = G.n;
    for(int i = 0; i < G.n; i++)
    {
        for(int j = 0; j < G.n; j++)
        {
            if(i == front && j == rear)
                M.edges[i][j] = INF;
            else
                M.edges[i][j] = G.edges[i][j];
        }
    }
    
    cout<<"邻接矩阵删除边新";
    DispGraph(M);
}

 
void InsertGraph_v(MatGraph G)      //插入结点
{
    int end,num,i,j;    //新结点的头和权重
    cout<<"请输入插入新结点的一条路终点与权值:"<<endl;
    cin>>end>>num;
    MatGraph M;
    M.n = G.n + 1;
    M.e = G.e + 1;
    for(i = 0; i < M.n; i++)
    {
        for(j = 0; j < M.n; j++)
        M.edges[i][j] = G.edges[i][j];
    }
    for(i = 0; i < M.n; i++)
    M.edges[i][M.n-1] = INF;
    for(j = 0; j < M.n; j++)
    {
        if(j == end-1)
        {
            M.edges[M.n-1][j] = num;
        }
        else
            M.edges[M.n-1][j] = INF;
    }
    DispGraph(M);
}


void InsertGraph_e(MatGraph G)      //插入边
{
    int start,end,num;
    cout<<"请输入插入边的起点、终点及权值:"<<endl;
    cin>>start>>end>>num;
    MatGraph M;
    M.n = G.n;
    M.e = G.e + 1;
    for(int i = 0; i < M.n; i++)
    {
        for(int j = 0; j < M.n; j++)
        {
            if(i == start-1 && j == end-1)
            {
                M.edges[i][j] = num;
            }
            else
                M.edges[i][j] = G.edges[i][j];
        }
    }
    DispGraph(M);
}



//✅邻接表的实现
void CreateAdj(AdjGraph *&G,int n,int e,int A[MAXV][MAXV])  //创建邻接表
{
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    G->n = n;
    G->e = e;
    for(int i = 0; i < n; i++)      //初始化：弧的指针全置为NULL
    G->adjlist[i].firstarc = NULL;
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j >= 0; j--)     //因为用头插法 所有j倒着走
        {
            if(A[i][j] != 0 && A[i][j] != INF)
            {
                ArcNode * p;
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p -> adjvex = j;
                p -> weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;     //头插法插入
                G->adjlist[i].firstarc = p;
            }
        }
    }
}


void DispAdj(AdjGraph *G)   //输出邻接表
{
    cout<<"图的邻接表为:"<<endl;
    ArcNode *p;
    for(int i = 0; i < G->n ; i++)
    {
        p = G->adjlist[i].firstarc;
        cout<<setw(3)<<i<<"->";
        while(p != NULL)
        {
            cout<<p->adjvex<<"["<<p->weight<<"]"<<"->";
            p = p->nextarc;
        }
        cout<<"^"<<endl;
    }
}

//——————————————————————————————————————
void DeleAdj_v(AdjGraph *G)        //邻接表结点v的删除
{
    G->n--;
    int v;
    cout<<"请输入删除的结点:"<<endl;
    cin>>v;
    ArcNode * p;
    for(int i = v; i < G->n; i++)
    {
        G->adjlist[i].firstarc = NULL;
        p = G->adjlist[i+1].firstarc;     //p指向下一个结点的
        while(p)
        {
            ArcNode * q;
            q = (ArcNode *)malloc(sizeof(ArcNode));
            q -> adjvex = p->adjvex;
            q -> weight = p->weight;
            q->nextarc = G->adjlist[i].firstarc;     //头插法插入
            G->adjlist[i].firstarc = q;
            p = p->nextarc;
        }
        p = NULL;
    }
    
    
    for(int i = 0; i < G->n; i++)
    {
        ArcNode * p, *q;
        p = G->adjlist[i].firstarc;
        q = NULL;
        while(p)
        {
            if(p->adjvex == v)
            {
                if(q == NULL)
                {
                    G->adjlist[i].firstarc = p->nextarc;
                    p = NULL;
                }
                else
                {
                    q->nextarc = p->nextarc;
                    p = NULL;
                }
            }
            else
            {
                q = p;
                p = p->nextarc;
            }
        }
    }
    
    
    for(int i = 0; i < G->n ; i++)
    {
        p = G->adjlist[i].firstarc;
        while (p)
        {
            if(p->adjvex > v)
            {
                p->adjvex --;
            }
            p = p->nextarc;
        }
    }
    
    DispAdj(G);
}


void DeleAdj_e(AdjGraph *G)        //邻接表边e的删除
{
    G->e--;    //边少一个
    int front,rear;
    cout<<"请输入删除边的头、尾结点:"<<endl;
    cin>>front>>rear;
    ArcNode *p,*q;
    p = G->adjlist[front].firstarc;
    q = NULL;    //q是前驱指针
    while (p)
    {
        if(p->adjvex == rear)    //找到该边
        {
            if(q == NULL)   //当第一条边就满足条件
            {
                G->adjlist[front-1].firstarc = p->nextarc;
            }
            else    //该边是中间的边
            {
                q->nextarc = p->nextarc;
                p = NULL;
            }
        }
        else
        {
            q = p;
            p = p->nextarc;
        }
    }
    DispAdj(G);
}


void InsertAdj_v(AdjGraph *G)        //邻接表结点v的插入
{
    G->n++;
    int end,num;    //新结点的头和权重
    cout<<"请输入插入新结点的一条路终点与权值:"<<endl;
    cin>>end>>num;
    ArcNode * p;
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p -> adjvex = end;
    p -> weight = num;
    p -> nextarc = NULL;
    G -> adjlist[G->n-1].firstarc = p;     //头插法插入
    
    DispAdj(G);
}


void InsertAdj_e(AdjGraph *G)        //邻接表边e的插入
{
    G->e++;
    int start,end,num;
    cout<<"请输入插入边的起点、终点及权值:"<<endl;
    cin>>start>>end>>num;
    ArcNode * p;
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p -> adjvex = end;
    p -> weight = num;
    p->nextarc = G->adjlist[start].firstarc;     //头插法插入
    G->adjlist[start].firstarc = p;
    
    DispAdj(G);
}


void DFS_Adj(AdjGraph *G,int v)    //递归深度优先遍历算法
{
    ArcNode *p;
    cout<<v<<" ";
    visited[v] = 1;   //访问v，并置已访问标记
    p = G->adjlist[v].firstarc;
    while (p != NULL)
    {
        if(visited[p->adjvex] == 0)
            DFS_Adj(G,p->adjvex);
        p = p -> nextarc;
    }
}



void BFS_Adj(AdjGraph *G,int v)   //广度优先遍历算法
{
    ArcNode *p;
    int queue[MAXV],front = 0, rear = 0;    //定义环形队列并初始化
    int visited[MAXV];   //定义存放顶点的访问标志的数组
    int w;
    for(int i = 0; i < G->n; i++)
        visited[i] = 0;
    
    cout<<v<<" ";
    visited[v] = 1;
    rear = (rear + 1) % MAXV;
    queue[rear] = v;    //v进队
    while (front != rear)
    {
        front = (front +1) % MAXV;
        w = queue[front];     //出队并赋给w
        p = G -> adjlist[w].firstarc;    //找v的邻接点
        while( p != NULL)
        {
            if(visited[p->adjvex] == 0)   //相邻点未被访问
            {
                cout<<p->adjvex<<" ";
                visited[p->adjvex] = 1;    //该点访问了置为1
                rear = (rear + 1) % MAXV;
                queue[rear] = p -> adjvex;
            }
            p = p->nextarc;       //找下一个相邻点
        }
    }
    cout<<endl;
}


int main()
{
    MatGraph G1;
    AdjGraph *G2;
    int A[MAXV][MAXV];
    int n,e;
    cout<<"请输入图的顶点数和边数:"<<endl;
    cin>>n>>e;
    cout<<"请输入图的信息:"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        cin>>A[i][j];
    }
    CreateGraph(G1, n, e, A);     //创建邻接矩阵
    DispGraph(G1);     //输出邻接矩阵
    
    CreateAdj(G2, n, e, A);      //创建邻接矩表
    DispAdj(G2);       //输出邻接表
    
    DeleGraph_v(G1);     //删除矩阵结点
    DeleGraph_e(G1);    //删除矩阵边
    
    int v;
    cout<<"请输入遍历顶点:"<<endl;
    cin>>v;
    cout<<"邻接表深度优先遍历算法为:"<<endl;
    DFS_Adj(G2,v);
    cout<<endl;
    cout<<"邻接表广度优先遍历算法为:"<<endl;
    BFS_Adj(G2, v);
    
    InsertGraph_v(G1);   //插入矩阵的结点
    InsertGraph_e(G1);   //插入矩阵的边

    DeleAdj_e(G2);   //删除表的边
    DeleAdj_v(G2);   //删除表的结点
    
    InsertAdj_v(G2);  //插入表的结点
    InsertAdj_e(G2);  //插入表的边
}
