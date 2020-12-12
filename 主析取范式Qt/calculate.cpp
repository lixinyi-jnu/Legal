#include "calculate.h"

char OPSET[7] = {'!','*','|','-','=','(',')'};     //存放连接词

Calculate::Calculate(string str)
{
    formular = str;
    temp = str;
    num = 0;
}

int Calculate::In(char c)   //判断是否为运算符  是返回1 不是返回0
{
    for(int i =0; i < Opnum; i++)
    {
        if(c == OPSET[i])     //是连接词返回1
            return 1;
    }
    return 0;
}


int Calculate::Exist(char c)      //排除重复原子命题  如果已经存在该命题返回1 没有返回0
{
    for(int i = 0; i < num; i++)
    {
        if(c == var[i])
            return 1;
    }
    return 0;
}

void Calculate::Judge()    //判断有几个原子命题  注意不要重复算相同命题
{
    int k = 0;
    for(int i = 0; formular[i] != '\0'; i++)
    {
        if(In(formular[i]))    //如果是连接词继续循环
            continue;
        else
        {
            if(Exist(formular[i]))  //存在该命题了
                continue;
            else
            {
                var[k++] = formular[i];    //如果是原子命题就保存在string var里
                num = k;
            }
        }
    }
    //num = k;    //得到原子命题个数
}

void Calculate::ToValue()   //给原子命题赋真值  得到 （0-0)-0
{
    //如果不在OPSET连接词中 就给它赋该行的对应真值
    for(int i = 0; i < int(formular.size()); i++) //遍历formular表达式
    {
        if(!In(formular[i]))     //不是连接词 是原子命题时
        {
            formular.replace(i, 1, alphabet[formular[i] - 'A'] ? "1" : "0");
        }
    }
}

void Calculate::Deletekuohao()
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i] == '(' && formular[i+2] == ')' && formular[i+1] == '1')
            formular.replace(i,3,"1");
        else if(formular[i] == '(' && formular[i+2] == ')' && formular[i+1] == '0')
            formular.replace(i,3,"0");
    }
}

void Calculate::Fei()   //'!'
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i] == '!' && formular [i+1] == '1')
            formular.replace(i,2,"0");
        else if(formular[i] == '!' && formular [i+1] == '0')
            formular.replace(i,2,"1");
    }
}


void Calculate::Hequ()   //'*'
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i+1] == '*' && formular[i] == '0' && formular[i+2] == '0')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '*' && formular[i] == '0' && formular[i+2] == '1')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '*' && formular[i] == '1' && formular[i+2] == '0')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '*' && formular[i] == '1' && formular[i+2] == '1')
            formular.replace(i,3,"1");
    }
}


void Calculate::Xiqu()   //'|'
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i+1] == '|' && formular[i] == '0' && formular[i+2] == '0')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '|' && formular[i] == '0' && formular[i+2] == '1')
            formular.replace(i,3,"1");
        else if(formular[i+1] == '|' && formular[i] == '1' && formular[i+2] == '0')
            formular.replace(i,3,"1");
        else if(formular[i+1] == '|' && formular[i] == '1' && formular[i+2] == '1')
            formular.replace(i,3,"1");
    }
}

void Calculate::Tiaojian()  //'-'
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i+1] == '-' && formular[i] == '0' && formular[i+2] == '0')
            formular.replace(i,3,"1");
        else if(formular[i+1] == '-' && formular[i] == '0' && formular[i+2] == '1')
            formular.replace(i,3,"1");
        else if(formular[i+1] == '-' && formular[i] == '1' && formular[i+2] == '0')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '-' && formular[i] == '1' && formular[i+2] == '1')
            formular.replace(i,3,"1");
    }
}

void Calculate::Shuangtiaojian()    //'='
{
    for(int i = 0; i < int(formular.size()); i++)
    {
        if(formular[i+1] == '=' && formular[i] == '0' && formular[i+2] == '0')
            formular.replace(i,3,"1");
        else if(formular[i+1] == '=' && formular[i] == '0' && formular[i+2] == '1')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '=' && formular[i] == '1' && formular[i+2] == '0')
            formular.replace(i,3,"0");
        else if(formular[i+1] == '=' && formular[i] == '1' && formular[i+2] == '1')
            formular.replace(i,3,"1");
    }
}

void Calculate::DrawTable()
{
    for(int i = 0 ; i < pow(2, num); i++)
    {
        for(int j = 0; j < num; j++)
        {//位运算赋值 给该行的命题变元赋0、1值
            alphabet[var[j] - 'A'] = (1 & (i >> (num - 1 - j)));
        }
        for(int j = 0; j < num; j++)
        {
            TruthTable[i][j] = alphabet[var[j] - 'A'];
        }
        ToValue();
        while(int(formular.size()) != 1)  //长度为1时就是最终结果了
        {
            //原则：五个连接词按优先级次序（非>合取>析取>条件>双条件）
            //每进一个连接词内是将全部表达式做处理，并不是一个字符一个字符的验证
            int min = int(formular.size());
            Deletekuohao();
            if(int(formular.size()) < min)
                continue;
            Fei();
            if(int(formular.size()) < min)
                continue;
            Hequ();
            if(int(formular.size()) < min)
                continue;
            Xiqu();
            if(int(formular.size()) < min)
                continue;
            Tiaojian();
            if(int(formular.size()) < min)
                continue;
            Shuangtiaojian();
            if(int(formular.size()) < min)
                continue;
        }
        TruthTable[i][num] = formular[0] - '0'; //把formular最后的值赋给真值表的结果列
        formular = temp; //将formular重新改为原命题再次赋值
    }
}



void Calculate::BiToTen()
{
    for(int i = 0; i <= pow(2, num); i++)
    {
        int sum = 0;
        if(TruthTable[i][num] == 1)      //该行的结果为真
        {
            int temp = num-1;    //保存一个备用num值
            for(int j = 0; j < num; j++)
            {
                sum += TruthTable[i][j] * pow(2, temp--);
            }
            result.push_back(sum);
        }
        else
            continue;
    }

}
