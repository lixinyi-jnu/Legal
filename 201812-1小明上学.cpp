#include <iostream>
using namespace std;

int main()
{
    int r,y,g,n,i,j;
    cin>>r>>y>>g;   //输入红、黄、绿灯时间
    cin>>n; //输入路的条数
    int Road[n][2];
    int Time = 0;
    for(i = 0; i < n; i++)
        for(j =0; j < 2; j++)
        {
            cin>>Road[i][j];
        }
    for(i = 0; i < n; i++)
    {
        if (Road[i][0] == 0)
            Time += Road [i][1];
        if (Road[i][0] == 1)
        {
            if(Time > Road[i][1])
               Time += 0;
        }
        if(Road [i][0] == 2)
            Time += (r-(Time -Road[i][1]));
        if(Road[i][0] == 3)
        {
            int temp = Time - Road[i][1];
            Time += r - (temp - y);
        }
    }
    cout<<Time<<endl;
}
