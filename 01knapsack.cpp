#include<iostream>
#include<vector>
using namespace std;

int solve(int wt[],int val[],int n,int w,vector<vector<int>>& dp){
    if(n==0 || w==0){
        return 0;
    }

    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(wt[n-1]<=w){
        int excl=0+solve(wt,val,n-1,w,dp);
        int incl=val[n-1]+solve(wt,val,n-1,w-wt[n-1],dp);
        return dp[n][w]=max(excl,incl);
    }
    else if(wt[n-1]>w){
        int excl=0+solve(wt,val,n-1,w,dp);
        return dp[n][w]=excl;
    }
}

int knapsack(int wt[],int val[],int n,int w){
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return solve(wt,val,n,w,dp);
}

int main(){
    int n=3;
    int w=4;
    int val[]={1,2,3};
    int wt[]={4,5,6};

    cout<<"The Maximum Profit is "<<knapsack(wt,val,n,w)<<endl;

    return 0;
}