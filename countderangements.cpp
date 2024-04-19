#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>& dp){
    if(n==1){
        return 0;
    }
    
    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=(n-1)*(solve(n-2,dp)+solve(n-1,dp));
    return dp[n]=ans;
}

int countDerangements(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The number of derangements Possible is "<<countDerangements(n)<<endl;

    return 0;
}