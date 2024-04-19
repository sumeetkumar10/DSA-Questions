#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>& dp){
    if(n==0) return 0;

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solve(n-i*i,dp));
    }
    return dp[n]=ans;
}

int getMinimumSquares(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The minimum number of square numbers required to get "<<n<<" is "<<getMinimumSquares(n)<<endl;

    return 0;
}