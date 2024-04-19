#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    vector<int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        int first=dp[i-2];
        int second=dp[i-1];

        int ans=(i-1)*(first+second);
        dp[i]=ans;
    }
    return dp[n];
}

int countDerangements(int n){
    return solve(n);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The number of derangements Possible is "<<countDerangements(n)<<endl;

    return 0;
}