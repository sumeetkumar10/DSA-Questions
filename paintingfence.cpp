#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int k,vector<int>& dp){
    if(n==1){
        return k;
    }

    if(n==2){
        return (k+k*(k-1));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int same=(k-1)*solve(n-2,k,dp);
    int different=(k-1)*solve(n-1,k,dp);

    return dp[n]=same*different;
}

int numberOfWays(int n,int k){
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

int main(){
    int n;
    cout<<"Enter the number of posts"<<endl;
    cin>>n;

    int k;
    cout<<"Enter the number of colors"<<endl;
    cin>>k;

    cout<<"The number of ways to color "<<n<<" posts with "<<k<<" colors is "<<numberOfWays(n,k)<<endl;

    return 0;
}