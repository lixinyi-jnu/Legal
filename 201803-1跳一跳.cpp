#include <iostream>
 
using namespace std;
int main(){
    int n ,L , t;
    cin>>n>>L>>t;
    int location[n];
    int direction[n];
    for(int i=0;i<n;i++)
    {
        direction[i]=1;
        cin>>location[i];
    }
    
    
    for(int time=1;time<=t;time++)
    {
        for(int i=0;i<n;i++)
        {
            location[i]+=direction[i];
            if(location[i]==L||location[i]==0)   //是否在端点或0点
                direction[i]*=(-1);
        }
        bool ischeck[n];
        for(int i=0;i<n;i++)
        {
            ischeck[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(ischeck[i]==false)
            {
                for(int j=0;j<n;j++)
                {
                    if(location[i]==location[j]&&i!=j)
                    {
                        direction[i]*=(-1);
                        direction[j]*=(-1);
                        ischeck[i]=true;
                        ischeck[j]=true;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<location[i]<<" ";
    }
    return 0;
}

