/*
 7 12

0 4 6 6 32767 32767 32767
32767 0 1 32767 7 32767 32767
32767 32767 0 32767 6 4 32767
32767 32767 2 0 32767 5 32767
32767 32767 32767 32767 0 32767 6
32767 32767 32767 32767 1 0 8
32767 32767 32767 32767 32767 32767 0
 */


/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.12.10
 最后修改时间：2020.12.18
 */

/*
 文件中定义的函数名称和主要功能
 void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e)   //创建图的邻接矩阵
 void DispMat(MatGraph g)      //输出邻接矩阵
 void CreateAdj(AdjGraph *&G,int n,int e,int A[MAXV][MAXV])  //创建邻接表
 void DispAdj(AdjGraph *G)   //输出邻接表
 void Dispath(MatGraph g,int dist[],int path[],int S[],int v)     //输出路径
 void Dijkstra(MatGraph g,int v)       //Dijkstra算法
 void Prim(MatGraph g,int v)   //Prim算法
 bool TopSort(AdjGraph *G,int topseq[])    //拓扑排序
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
using namespace std;
#define INF 32767
#define MAXV 100


//邻接矩阵
typedef struct
{
    int no;       //顶点编号
    char info;   //顶点其他信息
}VertexType;

typedef struct {
    int edges[MAXV][MAXV];   //邻接矩阵数组
    int n,e;    //n是顶点数 e是权重
    VertexType vexs[MAXV];
}MatGraph;



//邻接表类型
typedef struct ANode
{
    int adjvex;   //该弧所指向的顶点的位置
    struct ANode * nextarc;    //指向下一条边的指针
    int weight;    //权重
}ArcNode;   //边结点类型

typedef struct Vnode
{
    char info;    //顶点信息
    int count;
    ArcNode *firstarc;   //指向第一条边
}VNode;    //邻接表头结点类型

typedef struct
{
    VNode adjlist[MAXV];     //邻接边头结点数组
    int n,e;    //图中顶点数n和边树e
}AdjGraph;     //邻接表类型


/*
 函数名称：CreateMat
 函数主要功能：创建图的邻接矩阵
 函数调用之前的预备条件：无
 函数的输入参数：MatGraph &g,int A[MAXV][MAXV],int n,int e
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e)   //创建图的邻接矩阵
{
    int i,j;
    g.n = n;
    g.e = e;
    for(i = 0; i < g.n; i++)
    {
        for(j = 0; j < g.n; j++)
        g.edges[i][j] = A[i][j];
    }
}


/*
 函数名称：DispMat
 函数主要功能：输出邻接矩阵
 函数调用之前的预备条件：无
 函数的输入参数：MatGraph g
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void DispMat(MatGraph g)      //输出邻接矩阵
{
    cout<<"该图的邻接矩阵为:"<<endl;
    int i,j;
    for(i = 0; i < g.n; i++)
    {
        for(j = 0;j < g.n; j++)
        {
            if(g.edges[i][j]!=INF)
                printf("%3d",g.edges[i][j]);
            else
                printf("%5s","∞");
        }
        cout<<endl;
    }
}


/*
 函数名称：CreateAdj
 函数主要功能：创建邻接表
 函数调用之前的预备条件：无
 函数的输入参数：AdjGraph *&G,int n,int e,int A[MAXV][MAXV]
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
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

/*
 函数名称：DispAdj
 函数主要功能：输出邻接表
 函数调用之前的预备条件：无
 函数的输入参数：AdjGraph *G
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
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

/*
 函数名称：Dispath
 函数主要功能：输出路径
 函数调用之前的预备条件：无
 函数的输入参数：MatGraph g,int dist[],int path[],int S[],int v
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Dispath(MatGraph g,int dist[],int path[],int S[],int v)     //输出路径
{
    int i,j,k;
    int apath[MAXV],d;
    for(i = 0; i < g.n; i++)
    if(S[i] == 1 && i != v)
    {
        cout<<"从顶点"<<v<<"到顶点"<<i<<"的路径长度为:"<<dist[i]<<"路径为:";
        d = 0;
        apath[d] = i;
        k = path[i];
        if(k == -1)
            cout<<"无路径"<<endl;
        else
        {
            while( k!= v)
            {
                d++;
                apath[d] = k;
                k = path[k];
            }
            d++;
            apath[d] = v;
            cout<<apath[d];
            for(j = d-1; j >= 0; j--)
            cout<<","<<apath[j];
            cout<<endl;
        }
    }
}


/*
 函数名称：Dijkstra
 函数主要功能：Dijkstra算法
 函数调用之前的预备条件：无
 函数的输入参数：MatGraph g,int v
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Dijkstra(MatGraph g,int v)       //Dijkstra算法
{
    int dist[MAXV],path[MAXV];
    int S[MAXV];
    int Mindis,i,j,u = 0;
    for(i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];
        S[i] = 0;
        if(g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
        S[v] = 1;
        path[v] = 0;
        for(i = 0; i < g.n-1; i++)
        {
            Mindis = INF;
            for(j = 0; j < g.n; j++)
            {
                if(S[j] == 0 && dist[j] < Mindis)
                {
                    u = j;
                    Mindis = dist[j];
                }
            }
            S[u] = 1;
            for(j = 0; j < g.n; j++)
            {
                if(S[j] == 0)
                    if(g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                    {
                        dist[j] = dist[u] + g.edges[u][j];
                        path[j] = u;
                }
            }
        }
    Dispath(g,dist,path,S,v);     //输出最短路径
}


/*
 函数名称：Prim
 函数主要功能：Prim算法
 函数调用之前的预备条件：无
 函数的输入参数：MatGraph g,int v
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Prim(MatGraph g,int v)   //Prim算法
{
    int lowcost[MAXV],min,n = g.n;
    int closet[MAXV],i,j,k = 0;
    for(i = 0; i < n; i++)    //赋初值
    {
        lowcost[i] = g.edges[v][i];
        closet[i] = v;
    }
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 0; j < n; j++)
        if(lowcost[j] != 0 && lowcost[j] < min)
        {
            min = lowcost[j];
            k = j;
        }
        cout<<"边("<<closet[k]<<","<<k<<")"<<"权为:"<<min<<endl;
        lowcost[k] = 0;
        for(j = 0; j < n; j++)
        {
            if(g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closet[j] = k;
            }
        }
    }
}



/*
 函数名称：TopSort
 函数主要功能：拓扑排序
 函数调用之前的预备条件：无
 函数的输入参数：AdjGraph *G,int topseq[]
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
bool TopSort(AdjGraph *G,int topseq[])    //拓扑排序
{
    int i,j,n = 0;
    int st[MAXV];
    int top = -1;
    ArcNode *p;
    for(i = 0; i < G->n; i++)
    G->adjlist[i].count = 0;
    for(i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        while( p!= NULL)
        {
            G->adjlist[p->adjvex].count++;
            p = p->nextarc;
        }
    }
    for(i = 0; i < G->n; i++)
    if(G->adjlist[i].count == 0)
    {
        top++;
        st[top] = i;
    }
    while( top > -1 )
    {
        i = st[top];
        top --;
        topseq[n] = i;
        n++;
        p = G->adjlist[i].firstarc;
        while(p != NULL)
        {
            j = p->adjvex;
            G->adjlist[j].count--;
            if(G->adjlist[j].count == 0)
            {
                top++;
                st[top] = j;
            }
            p = p->nextarc;
        }
    }
    if(n < G->n)
        return false;
    else
    {
        cout<<"拓扑排序:";
        for( i = 0; i < n; i++)
        cout<<(topseq[i]);
        cout<<endl;
        return true;
    }
}


int main()
{
    int v = 0;
    int n,e;
    cout<<"请输入图的顶点和边数:"<<endl;
    cin>>n>>e;
    MatGraph g;
    AdjGraph *G;
    int A[MAXV][MAXV];
    cout<<"请输入图的内容:"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        cin>>A[i][j];
    }
    CreateMat(g,A,n,e);
    DispMat(g);
    cout<<"Dijkstra算法结果如下:"<<endl;
    Dijkstra(g, v);
    
    cout<<"Prim算法结果如下:"<<endl;
    Prim(g, 0);
    
    CreateAdj(G, n, e, A);
    DispAdj(G);
    int topseq[MAXV];
    TopSort(G, topseq);
}

