#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solve(int n){
    vector<int> dp(n+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            int temp=j*j;
            if((i-temp)>=0){
                dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
    }
    return dp[n];
}

int getMinimumSquares(int n){
    return solve(n);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The minimum number of square numbers required to get "<<n<<" is "<<getMinimumSquares(n)<<endl;

    return 0;
}