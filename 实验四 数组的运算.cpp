/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.11.3
 最后修改时间：2020.11.13
 */
/*
 文件中定义的函数名称和主要功能
 void CreateSMatrix(TSMatrix &M)   //创建矩阵
 void PrintSMatrix(TSMatrix M)   //输出矩阵及其三元组
 void Insert(TSMatrix &M1,int a,TSMatrix M2,int b)    //将M2[b]插入M1[a]
 void AddSMatrix(TSMatrix M1,TSMatrix M2,TSMatrix &M3)    //矩阵求和
 int FindNum(TSMatrix M,int i,int j)    //在矩阵中寻找元素
 void MultSMatrix(TSMatrix M1,TSMatrix M2)     //矩阵求乘积
 void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)   //矩阵快速转置法
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
#define MAXSIZE 12500    //假设非零元个数的最大值为12500

typedef struct     //三元组
{
    int i,j;   //该非零元的行下标和列下标
    int e;
}Triple;

typedef struct    //矩阵
{
    Triple data[MAXSIZE+1];    //非零元三元组表，data[0]未用
    int mu,nu,tu;    //矩阵的行数、列数和非零元个数
}TSMatrix;



/*
 函数名称：CreateSMatrix
 函数主要功能：创建矩阵
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix &M
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void CreateSMatrix(TSMatrix &M)    //创建矩阵
{
    int m, n, z;
    cout<<"请分别输入矩阵的行数、列数和非零元个数:"<<endl;
    cin>>m>>n>>z;
    M.mu = m;
    M.nu = n;
    M.tu = z;
    cout<<"请输入非零元的行下标、列下标和数字:"<<endl;
    for(int i = 1; i <= M.tu; i++)
    {
        cin>>M.data[i].i>>M.data[i].j>>M.data[i].e;
    }
}


/*
 函数名称：PrintSMatrix
 函数主要功能：//输出矩阵及其三元组
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix M
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被FastTransposeSMatrix、AddSMatrix、main函数调用
 */
void PrintSMatrix(TSMatrix M)   //输出矩阵及其三元组
{
    int i,j,k = 1;
    for(i = 1; i <= M.mu; i++)
    {
        for(j = 1; j <= M.nu; j++)
        {
            if(M.data[k].i == i && M.data[k].j == j)
            {
                cout<<setw(5)<<M.data[k].e;
                k++;
            }
            else
                cout<<setw(5)<<"0";
        }
        cout<<endl;
    }
    cout<<"对应三元组表示如下:"<<endl;
    
    cout<<"("<<M.mu<<","<<M.nu<<","<<M.tu<<")"<<endl;
    for(i = 1; i <= M.tu; i++)
    {
        cout<<"("<<M.data[i].i<<","<<M.data[i].j<<","<<M.data[i].e<<")"<<endl;
    }
}


/*
 函数名称：Insert
 函数主要功能：将M2[b]插入M1[a]
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix &M1,int a,TSMatrix M2,int b
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被AddSMatrix函数调用
 */
void Insert(TSMatrix &M1,int a,TSMatrix M2,int b)    //将M2[b]插入M1[a]
{
    M1.data[a].e = M2.data[b].e;
    M1.data[a].i = M2.data[b].i;
    M1.data[a].j = M2.data[b].j;
    M1.tu++;
}



/*
 函数名称：AddSMatrix
 函数主要功能：矩阵求和
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix M1,TSMatrix M2,TSMatrix &M3
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void AddSMatrix(TSMatrix M1,TSMatrix M2,TSMatrix &M3)    //矩阵求和
{
    M3.mu = M1.mu;   //初始化M3
    M3.nu = M1.nu;
    M3.tu = 0;
    int i = 1,j = 1,k = 1;
    while(i <= M1.tu && j <= M2.tu)      //i是M1非零元素指针 j是M2指针
    {
        if(M1.data[i].i < M2.data[j].i)
        {
            Insert(M3, k, M1, i);
            k++;
            i++;
        }
        else if(M2.data[j].i < M1.data[i].i)
        {
            Insert(M3, k, M2, j);
            k++;
            j++;
        }
        else if(M1.data[i].i == M2.data[j].i)
        {
            if(M1.data[i].j < M2.data[j].j)
            {
                Insert(M3, k, M1, i);
                k++;
                i++;
            }
            else if(M1.data[i].j > M2.data[j].j)
            {
                Insert(M3, k, M2, j);
                k++;
                j++;
            }
            else
            {
                M3.data[k].e = M1.data[i].e + M2.data[j].e;
                M3.data[k].i = M2.data[j].i;
                M3.data[k].j = M2.data[j].j;
                M3.tu++;
                k++;
                i++;
                j++;
            }
        }
    }
    while(i <= M1.tu)
    {
        Insert(M3, k, M1, i);
        k++;
        i++;
    }
    while (j <= M2.tu)
    {
        Insert(M3, k, M2, j);
        k++;
        j++;
    }
    cout<<"相加后的矩阵为:"<<endl;
    PrintSMatrix(M3);
}



/*
 函数名称：FindNum
 函数主要功能：在矩阵中寻找元素
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix M,int i,int j
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被MultSMatrix函数调用
 */
int FindNum(TSMatrix M,int i,int j)    //在矩阵中寻找元素
{
    int k;
    for(k = 1; k <= M.tu; k++)
    {
        if(M.data[k].i == i && M.data[k].j == j)
            return M.data[k].e;
    }
    return 0;
}



/*
 函数名称：MultSMatrix
 函数主要功能：矩阵求乘积
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix M1,TSMatrix M2
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void MultSMatrix(TSMatrix M1,TSMatrix M2)     //矩阵求乘积
{
    TSMatrix Temp;
    Temp.tu = 0;
    Temp.mu = M1.mu;
    Temp.nu = M2.nu;
    int z = 1;
    if(M1.nu != M2.mu)
    {
        cout<<"输入矩阵不能做乘法"<<endl;
        return;
    }
    else
    {
        cout<<"相乘后的矩阵如下:"<<endl;
        int i,j,k,sum = 0;
        for(i = 1; i <= M1.mu; i++)
        {
            for(j = 1; j <= M2.nu; j++)
            {
                sum = 0;
                for(k = 0; k <= M1.nu; k++)
                {
                    int a = FindNum(M1, i, k);
                    int b = FindNum(M2, k, j);
                    sum += a*b;
                }
                if(sum != 0)
                {
                    Temp.data[z].i = i;
                    Temp.data[z].j = j;
                    Temp.data[z].e = sum;
                    Temp.tu++;
                    z++;
                }
                cout<<setw(5)<<sum;
            }
            cout<<endl;
        }
    }
    cout<<"对应三元组表示如下:"<<endl;
    cout<<"("<<Temp.mu<<","<<Temp.nu<<","<<Temp.tu<<")"<<endl;
    for(int i = 1; i <= Temp.tu; i++)
    {
        cout<<"("<<Temp.data[i].i<<","<<Temp.data[i].j<<","<<Temp.data[i].e<<")"<<endl;
    }
}


/*
 函数名称：FastTransposeSMatrix
 函数主要功能：矩阵快速转置法
 函数调用之前的预备条件：无
 函数的输入参数：TSMatrix M,TSMatrix &T
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)   //矩阵快速转置法
{
    //num[col]表示矩阵M中第col列中非零元的个数
    //cpot[col]指示M中第col列的第一个非零元在b.data中的恰当位置
    int num[M.nu],cpot[M.nu];
    int col,t,p,q;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if(T.tu)
    {
        for(col = 1; col <= M.nu; col++)
            num[col] = 0;        //将每一列的非零元个数初始化为0
        for(t = 1; t<= M.tu; t++)
            ++num[M.data[t].j];    //求M中每一列含非零元个数
        cpot[1] = 1;
        //求第col列中第一个非零元在b.data中的序号
        for(col = 2; col <= M.nu; col++)
            cpot[col] = cpot[col-1] + num[col-1];
        for(p = 1; p <= M.tu; p++)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    cout<<"转置矩阵如下:"<<endl;
    PrintSMatrix(T);
}



int main()
{
    TSMatrix M1,M2,M3;
    CreateSMatrix(M1);
    cout<<"该矩阵如下:"<<endl;
    PrintSMatrix(M1);
    CreateSMatrix(M2);
    cout<<"该矩阵如下:"<<endl;
    PrintSMatrix(M2);
    AddSMatrix(M1, M2, M3);
    MultSMatrix(M1, M2);
    FastTransposeSMatrix(M1, M3);
}
