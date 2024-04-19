#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    int prev2=0;
    int prev1=1;

    for(int i=3;i<=n;i++){
        int first=prev2;
        int second=prev1;

        int ans=(i-1)*(first+second);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
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