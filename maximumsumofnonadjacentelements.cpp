#include<iostream>
#include<vector>
using namespace std;

int solve(int* arr,int i,int n,vector<int>& dp){
    if(i<0){
        return 0;
    }

    if(i==0){
        return arr[0];
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    int incl=arr[i]+solve(arr,i-2,n,dp);
    int excl=0+solve(arr,i-1,n,dp);

    return dp[i]=max(incl,excl);
}

int maxNonAdjacentSum(int* arr,int n){
    vector<int> dp(n+1,-1);
    return solve(arr,n-1,n,dp);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Maximum Sum of non-adjacent elements is "<<maxNonAdjacentSum(arr,n)<<endl;

    return 0;
}