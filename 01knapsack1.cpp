#include<iostream>
#include<vector>
using namespace std;

int solve(int wt[],int val[],int n,int w){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                int excl=0+dp[i-1][j];
                int incl=val[i-1]+dp[i-1][j-wt[i-1]];
                dp[i][j]=max(excl,incl);
            }
            else if(wt[i-1]>j){
                int excl=0+dp[i-1][j];
                dp[i][j]=excl;
            }
        }
    }
    return dp[n][w];
}

int knapsack(int wt[],int val[],int n,int w){
    return solve(wt,val,n,w);
}

int main(){
    int n=3;
    int w=3;
    int val[]={1,2,3};
    int wt[]={4,5,6};

    cout<<"The Maximum Profit is "<<knapsack(wt,val,n,w)<<endl;

    return 0;
}