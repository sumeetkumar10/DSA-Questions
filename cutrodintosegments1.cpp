#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solve(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        if((i-x)>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }
        if((i-y)>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }
        if((i-z)>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }
    if(dp[n]<0){
        return 0;
    }
    else{
        return dp[n];
    }
}

int maximumNumberOfSegments(int n,int x,int y,int z){
    return solve(n,x,y,z);
}

int main(){
    int n=7;
    int x=5;
    int y=2;
    int z=2;

    cout<<"The maximum number of segments in which the rod can be cut is "<<maximumNumberOfSegments(n,x,y,z);
    
    return 0;
}