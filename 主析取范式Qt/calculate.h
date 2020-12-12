#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
#include <vector>

#define Opnum 7     //定义连接词个数为7
using namespace std;


class Calculate
{
public:
    Calculate(string str);  //将表达式赋于formular和temp
    int Get_num(){return num;}
    string Get_var(){return var;}
    int In(char c);    //判断是否为运算符  是返回1 不是返回0
    int Exist(char c);    //排除重复原子命题
    void Judge();  //判断有几个原子命题
    void DrawTable();       //生成真值表
    void ToValue();     //给原子命题赋真值
    void Deletekuohao();    //出现单原子时把括号去了
    void Fei();     //非
    void Hequ();    //合取
    void Xiqu();    //析取
    void Tiaojian(); //条件
    void Shuangtiaojian(); //双条件
    void BiToTen();     //将二进制转换为10进制
    vector<int>result;
    int num;       //原子命题的个数
    int TruthTable[1000][1000] = {};     //真值表

private:
    string formular,temp;   //formular为输入的表达式 temp一直保存表达式  var保存原子命题
    char var[10];
//    int num;       //原子命题的个数
//    int TruthTable[1000][1000] = {};     //真值表
    int alphabet[30]={};   //因为变元为26个字母，在对应下标位置标记真值

};

#endif // CALCULATE_H
