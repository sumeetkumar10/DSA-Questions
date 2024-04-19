#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int k){
    int prev2=k;
    int prev1=k+k*(k-1);

    for(int i=3;i<=n;i++){
        int same=(k-1)*prev2;
        int different=(k-1)*prev1;

        int ans=same+different;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
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