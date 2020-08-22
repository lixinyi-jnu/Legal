//#include <iostream>
//using namespace std;
//const int Max = 2000;
//
//int main()
//{
//    int i,j;
//    long long a[Max][2],b[Max][2],n;
//    cin>>n;
//    int time = 0;
//    for(i = 0 ; i < n ; i++)
//        for(j = 0 ; j < 2; j++)
//            cin>>a[i][j];
//    for(i = 0 ; i < n ; i++)
//        for(j = 0 ; j < 2; j++)
//            cin>>b[i][j];
//    for(i = 0; i < n; i++)
//    {
//        if((a[i][0]<b[i][0])&&(a[i][1]<b[i][1]))
//            time += (a[i][1] - b[i][0]);
//        else if((b[i][0]<a[i][0])&&(b[i][1]<a[i][1]))
//            time += (b[i][1] - a[i][0]);
////        else if(((a[i][0]==b[i][0])&&(a[i][1]<b[i][1]))||((a[i][1]==a[i][1])&&(b[i][0]<a[i][0])))
////                time += (b[i][1]-a[i][0]);
////        else if(((a[i][0]==b[i][0])&&(b[i][1]<a[i][1]))||((a[i][1]==b[i][1])&&(a[i][0]<b[i][0])))
////                time += (b[i][1]-b[i][0]);
//        else if((a[i][0] >= b[i][0])&&(a[i][1]<=b[i][1]))
//            time += (a[i][1] - a[i][0]);
//        else if((a[i][0] <= b[i][0])&&(b[i][1]<=a[i][1]))
//            time += (b[i][1] - b[i][0]);
////        else if((a[i][1] == b[i][1])&&(b[i][0]<a[i][0]))
////            time += (b[i][1] - a[i][0]);
////        else if((a[i][1] == b[i][1])&&(a[i][0]<b[i][0]))
////            time += (b[i][0] - b[i][0]);
//        else if((a[i][1] <= b[i][0])||(b[i][1] <= a[i][0]))
//            time += 0;
//    }
//    cout<<time<<endl;
//}



#include<iostream>
using namespace std;

//区间结构体
struct Time{
    int from,to;
};

Time T1[2005];
Time T2[2005];

int main(){
    int n;
    cin>>n;
    int res = 0;
    //步骤1：输入小H的区间
    for(int i = 0; i < n; i ++){
        cin>>T1[i].from>>T1[i].to;
    }
    //步骤2：输入小W的区间
    for(int i = 0; i < n; i ++){
        cin>>T2[i].from>>T2[i].to;
    }
    for(int i = 0; i < n; i ++){
        //步骤3：逐一对比
        for(int j = 0 ; j < n ; j ++){
            //步骤4：如果小W的开始区间比小H的开始区间大，证明没有交集直接break到下一组
            if(T2[j].from >= T1[i].to){
                break;
            }
            /*/
            步骤5：
            如果小W的结束区间比小H的开始区间小，用下一组小W和这一组小H继续比
            这样可以防止小W错过小H的长区间
            例如：
            小H     小W
            5  10 | 3  4
            11 20 | 6  7
            21 30 | 8  9
            //*/
            if(T2[j].to <= T1[i].from){
                continue;
            }
            //步骤6：聊天时间=结束时间最小-开始时间最大
            //[11,20]  [12,15]  =  15 - 12 = 3
            res += min(T1[i].to,T2[j].to) - max(T1[i].from,T2[j].from);
        }
    }
    cout<<res;
    return 0;
}

