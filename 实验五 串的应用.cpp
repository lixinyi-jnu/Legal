/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.11.8
 最后修改时间：2020.11.22
 */
/*
 文件中定义的函数名称和主要功能
 void StrAssign(HString &S,char cstr[])    //生成等值于cstr的串s
 void Setlength(HString &S)      //设定串S的长度
 void GetWord(char article[],char word[],int &pos)    //提取单个单词
 void Init(SString &S, HString str)   //初始化串
 int Index(SString S, SString T, int pos)  // 返回子串T在主串S中第pos个字符之后的位置
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
#define MAXSTRLEN 255   //用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1];   //0号单元存放串的长度
using namespace std;


typedef struct
{
    char data[MAXSTRLEN];    //存放串字符
    int length;      //存放串长
}HString;



/*
 函数名称：StrAssign
 函数主要功能：生成等值于cstr的串s
 函数调用之前的预备条件：无
 函数的输入参数：HString &S,char cstr[]
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void StrAssign(HString &S,char cstr[])    //生成等值于cstr的串s
{
    int i;
    for(i = 0; cstr[i] != '\0'; i++)
        S.data[i] = cstr[i];
    S.length = i;
}



/*
 函数名称：Setlength
 函数主要功能：设定串S的长度
 函数调用之前的预备条件：无
 函数的输入参数：HString &S
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Setlength(HString &S)      //设定串S的长度
{
    int i;
    for(i = 0; S.data[i] != '\0'; i++);
    S.length = i;
}




/*
 函数名称：GetWord
 函数主要功能：提取单个单词
 函数调用之前的预备条件：无
 函数的输入参数：char article[],char word[],int &pos
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void GetWord(char article[],char word[],int &pos)    //提取单个单词
//pos是第每一次查找的索引值
{
    int index = 0,k = 0;
    for(int i = pos; article[i] != ' '&&article[i] != ','&&article[i] != '.'; i++)
    {
        word[k++] = article[i];
        index ++;
    }
    word[k] = '\0';
    pos += index + 1;
}


/*
 函数名称：Init
 函数主要功能：初始化串
 函数调用之前的预备条件：无
 函数的输入参数：SString &S, HString str
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
void Init(SString &S, HString str)   //初始化串
{
    int i = 0;
    while(str.data[i]!='\0')
    {
        S[i+1] = str.data[i];
        i++;
    }
    S[i+1] = '\0';
    S[0] = i;    //0号单元存放串的长度
}



/*
 函数名称：Index
 函数主要功能：返回子串T在主串S中第pos个字符之后的位置
 函数调用之前的预备条件：无
 函数的输入参数：SString S, SString T, int pos
 函数的输出参数：无
 函数的返回值：无
 该函数与其它函数的调用和被调用关系：被main函数调用
 */
int Index(SString S, SString T, int pos) {  // 算法4.5
   // 返回子串T在主串S中第pos个字符之后的位置。
   // 若不存在，则函数值为0。
   // 其中，T非空，1≤pos≤StrLength(S)。
    int i = pos;
    int j = 1;
    
    while (i <= S[0] && j <= T[0])
    {
       if (S[i] == T[j])
       {  // 继续比较后继字符
           ++i;
           ++j;
        }
       else
       {  // 指针后退重新开始匹配
           i = i-j+2;
           j = 1;
        }
   }
   if (j > T[0])
       return i-T[0];
   else return 0;
} // Index






int main()
{
    SString S,T;
    char article[500];     //按字符存了整篇文档
    int n,pos = 0;
    int a[100];    //保存每一个单词出现次数
    
    FILE *file = fopen("/Users/kanal/Desktop/24.txt", "r");
    fgets(article, 500, file);
    
    cout<<"请输入待匹配单词个数:"<<endl;
    cin>>n;
    HString Temp[n];
    cout<<"请输入待匹配单词:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>Temp[i].data;
        Setlength(Temp[i]);
    }
    for(int i = 0; article[i] != '\0'; i = pos)
    {
        char word[20];
        HString mid;
        GetWord(article, word, pos);
        StrAssign(mid, word);
        Init(S, mid);
        for(int j = 0; j < n; j++)
        {
            Init(T, Temp[j]);
            if(Index(S, T, 0) == 1)
            {
                a[j]++;
            }
        }
    }
    
    
    for(int i = 0; i < n; i++)
    {
        cout<<"关键词"<<Temp[i].data<<"出现次数:";
        cout<<a[i]<<endl;
    }
}
