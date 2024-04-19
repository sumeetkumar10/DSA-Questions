#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=k+k*(k-1);

    for(int i=3;i<=n;i++){
        int same=(k-1)*dp[i-2];
        int different=(k-1)*dp[i-1];

        dp[i]=same+different;
    }
    return dp[n];
}

int numberOfWays(int n,int k){
    return solve(n,k);
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