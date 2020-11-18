/*
 文件名称：main.cpp
 创建者姓名：李欣怡
 班级：计科1903
 学号：1033190308
 创建时间：2020.10.14
 最后修改时间：2020.10.30
 */

#include <iostream>
using namespace std;
#define OPSETSIZE 7   //运算符个数共7个
#define STACK_INIT_SIZE 100   //存储空间初始分配量
#define STACKINCREMENT 10    //存储空间分配增量




//运算符集合与下面二维数组行和列的顺序相同
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/' ,'(' , ')' , '#'};

unsigned char Prior[7][7] = {     // 表3.1  算符间的优先关系
    //'+' '-' '*' '/' '(' ')' '#'
      '>','>','<','<','<','>','>',
      '>','>','<','<','<','>','>',
      '>','>','>','>','<','>','>',
      '>','>','>','>','<','>','>',
      '<','<','<','<','<','=',' ',
      '>','>','>','>',' ','>','>',
      '<','<','<','<','<',' ','='
};
unsigned char Prior_2[7][7] = {     // 转前缀时用
      '>','<','<','<','<','>','>',
      '<','>','<','<','<','>','>',
      '>','>','>','<','<','>','>',
      '>','>','<','>','<','>','>',
      '<','<','<','<','<','=',' ',
      '>','>','>','>',' ','>','>',
      '<','<','<','<','<',' ','='
};



typedef struct    // 运算数栈，实数元素
{
    float *base;
    float *top;
    int stacksize;
}StackFloat;



typedef struct    // 运算符栈，字符元素
{
    char *base;
    char *top;
    int stacksize;
}StackChar;



void InitStack(StackChar &S)      //初始化运算符栈
{
    //构造一个空栈
    S.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
    if(!S.base)
        exit(0);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}



void InitStack(StackFloat &S)     //初始化运算数栈
{
    //构造一个空栈
    S.base = (float *)malloc(STACK_INIT_SIZE * sizeof(float));
    if(!S.base)
        exit(0);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}



void Push(StackChar &S,char e)   //插入元素e为新的栈顶元素
{
    if(S.top - S.base >= S.stacksize)   //栈满，追加存储空间
    {
        S.base = (char *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
        if(!S.base)
            exit(0);
    }
    *S.top++ = e;
}




void Push(StackFloat &S,float e)   //插入元素e为新的栈顶元素
{
    if(S.top - S.base >= S.stacksize)   //栈满，追加存储空间
    {
        S.base = (float *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(float));
        if(!S.base)
            exit(0);
    }
    *S.top++ = e;
}



char GetTop(StackChar S)     //得到运算符
{
    return *(S.top-1);
}



float GetTop(StackFloat S)     //得到运算数
{
    return *(S.top-1);
}



void Pop(StackChar &S,char &e) //若栈不空，则删除S的栈顶元素，用e返回其值
{
    e = *--S.top;
}



void Pop(StackFloat &S,float &e) //若栈不空，则删除S的栈顶元素，用e返回其值
{
    e = *--S.top;
}



float Operate(float a,unsigned char theta, float b)   //计算值 a+-*/b的
{
   switch(theta)
   {
      case '+': return a+b;
      case '-': return a-b;
      case '*': return a*b;
      case '/': return a/b;
      default : return 0;
   }
}



bool In(char Test,char* TestOp)   //找到该运算符返回true TestOp就是OPSET运算符数组
{
   for (int i=0; i< OPSETSIZE; i++)  //i<运算符个数7
    {
      if (Test == TestOp[i])
          return true;
   }
   return false;
}



int ReturnOpOrd(char op,char* TestOp)     //在OPSET运算符数组中返回该运算符下标
{
   int i;
   for(i=0; i< OPSETSIZE; i++)
    {
        if (op == TestOp[i])
            return i;
    }
   return 0;
}


char precede(char Aop, char Bop,unsigned char P[7][7])     //比较栈顶符号和正在比较的符号优先级
{
    int m,n;
    m = ReturnOpOrd(Aop,OPSET);
    n = ReturnOpOrd(Bop,OPSET);
    //return Prior[m][n];
    return P[m][n];
}



//将字符串倒置 在转前缀时用到 str1是原来的 str2是转置后的
void AdverseStr(char *str1,char *str2,int length)
{
    int k = 0;
    for(int i = length-1; i >= 0; i--)
    {
        if(str1[i] == '(')
            str2[k++] = ')';
        else if(str1[i] == ')')
            str2[k++] = '(';
        else
            str2[k++] = str1[i];
    }
    str2[k] = '\0';
}




float EvaluateExpression(char* MyExpression)
{
   // 算术表达式求值的算符优先算法。
   // 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合。
   StackChar  OPTR;    // 运算符栈，字符元素
   StackFloat OPND;    // 运算数栈，实数元素
   char TempData[20];
   float Data,a,b;
   char theta,*c,x,Dr[2];    //*c指向表达式
   
   InitStack (OPTR);    //初始化运算符栈
   Push (OPTR, '#');
   InitStack (OPND);    //初始化运算数栈
   c = MyExpression;
   strcpy(TempData,"\0");
    //可以让TempData变为字符串 因为在下面的atof中用的是字符串
   while (*c!= '#' || GetTop(OPTR)!= '#')     //未读到#时或未到栈底时
   {
      if (!In(*c, OPSET))     //不是运算符 是数字
      {
          Dr[0]=*c;
          Dr[1]='\0';
          strcat(TempData,Dr);   //把数字存在TempData数组里 其实里面只有一个数字
          c++;
         if(In(*c,OPSET))     //判断数字的下一个是字符->将数字入数据OPND栈 条件为真
         {
             //将char转化为float型的data double atof(const char *str)
            Data=(float)atof(TempData);
            Push(OPND, Data);    //让数据data入栈
            strcpy(TempData,"\0");   //将TempData重新置为空
         }
      }
      else
      {   // 不是运算符则进栈
         switch (precede(GetTop(OPTR), *c,Prior))
         {
            case '<':   // 栈顶元素优先权低
                 Push(OPTR, *c);
                 c++;
                 break;
            case '=':   // 脱括号并接收下一字符
                 Pop(OPTR, x);
                 c++;
                 break;
            case '>':   // 退栈并将运算结果入栈
                 Pop(OPTR, theta);    //a theta b （数 符号 数）
                 Pop(OPND, b);
                 Pop(OPND, a);
                 Push(OPND, Operate(a, theta, b));
                 break;
         } // switch
      }
   } // while
   return GetTop(OPND);   //返回运算数字栈顶
}



float EvaluateBack(char* MyExpression)
{
    char *c = MyExpression;
    strcat(c, "#");
    char TempData[20],Dr[2],theta;   //theta是运算符
    float Data,a,b;
    strcpy(TempData,"\0");
    
    StackFloat OPND;    // 运算数栈，实数元素
    InitStack(OPND);
    while (*c!= '#')     //未读到#时或未到栈底时
    {
        if (!In(*c, OPSET))     //不是运算符 是数字->Push
        {
            Dr[0]=*c;
            Dr[1]='\0';
            strcat(TempData,Dr);   //把数字存在TempData数组里 其实里面只有一个数字
            c++;
            
            //将char转化为float型的data double atof(const char *str)
            Data=(float)atof(TempData);
            Push(OPND, Data);    //让数据data入栈
            strcpy(TempData,"\0");   //将TempData重新置为空
        }
        else
        {
            theta = *c;
            Pop(OPND, b);
            Pop(OPND, a);
            Push(OPND, Operate(a, theta, b));
            c++;
        }
    }
    return GetTop(OPND);   //返回运算数字栈顶
}




float EvaluateFront(char* MyExpression)
{
    char *exp1 = MyExpression;     //exp1是原始的前缀表达式
    char *exp2;      //exp2是转置后的表达式
    int length = 0;
    for(int i = 0; exp1[i] != '\0';i++)
        length++;
    char F_adverse[length];
    exp2 = F_adverse;
    AdverseStr(exp1, exp2, length);
    
    
    char *c = exp2;
    strcat(c, "#");
    char TempData[20],Dr[2],theta;   //theta是运算符
    float Data,a,b;
    strcpy(TempData,"\0");
    
    StackFloat OPND;    // 运算数栈，实数元素
    InitStack(OPND);
    while (*c!= '#')     //未读到#时或未到栈底时
    {
        if (!In(*c, OPSET))     //不是运算符 是数字->Push
        {
            Dr[0]=*c;
            Dr[1]='\0';
            strcat(TempData,Dr);   //把数字存在TempData数组里 其实里面只有一个数字
            c++;
            
            //将char转化为float型的data double atof(const char *str)
            Data=(float)atof(TempData);
            Push(OPND, Data);    //让数据data入栈
            //cout<<Data;
            strcpy(TempData,"\0");   //将TempData重新置为空
        }
        else
        {
            theta = *c;
            Pop(OPND, a);
            Pop(OPND, b);
            Push(OPND, Operate(a, theta, b));
            //cout<<Operate(a, theta, b);
            c++;
        }
    }
    return GetTop(OPND);   //返回运算数字栈顶
}



char * MidToBack(char *exp1,char *exp2,unsigned char P[7][7])     //中缀转后缀
{
    int k = 0;
    char x,theta;    //保存运算符符号的
    char *c = exp1;
    StackChar  OPTR;    // 运算符栈，字符元素
    InitStack (OPTR);    //初始化运算符栈
    Push (OPTR, '#');
    
    while (*c!= '#' || GetTop(OPTR)!= '#')     //未读到#时或未到栈底时
    {
        if(*c > '0'&& *c < '9')   //遇到数字直接输出
        {
            exp2[k++] = *c;
            c++;
        }
        else     //遇到运算符
        {
            //switch (precede(GetTop(OPTR), *c))
            switch (precede(GetTop(OPTR), *c,P))
            {
               case '<':   // 栈顶元素优先权低
                    Push(OPTR, *c);
                    c++;
                    break;
               case '=':   // 脱括号并接收下一字符
                    Pop(OPTR, x);
                    c++;
                    break;
               case '>':   // 退栈并将运算结果入栈
                    Pop(OPTR, theta);
                    exp2[k++] = theta;
                    break;
            } // switch
        }
    }
    return exp2;
}


char *MidToFront(char *exp1,char *exp2)
{
    int length = 0,len = 0;
    for(int i = 0; exp1[i] != '#';i++)
        length++;
    char temp[length],final[length];
    char *exp_temp = temp;
    char *exp_final = final;
    AdverseStr(exp1, exp_temp, length);
    
    
    strcat(exp_temp, "#");
    MidToBack(exp_temp, exp_final,Prior_2);     //转换完结果是exp_final
    for(int i = 0; exp_final[i] != '\0'; i++)
        len++;
    AdverseStr(exp_final, exp2, len);
    if(exp2[0] == ')')
    {
        for(int i = 0; i < len; i++)
            exp2[i] = exp2[i+1];
    }
    return exp2;
}





int main()
{
    char Mid[20],Back[20],Front[20];
    char *mid, *back, *front;
    mid = Mid;
    back = Back;
    front = Front;
    cout<<"请输入要计算的中缀表达式(#表示输入结束):"<<endl;
    cin>>mid;
    cout<<"中缀计算结果为:"<<EvaluateExpression(mid)<<endl;
    cout<<"后缀表达式为:"<<MidToBack(mid, back,Prior)<<endl;
//    cout<<"后缀计算结果为:"<<EvaluateBack(back)<<endl;
//    cout<<"前缀表达式为:"<<MidToFront(mid, front)<<endl;
//    cout<<"前缀计算结果为:"<<EvaluateFront(front)<<endl;
    cout<<endl;
}


