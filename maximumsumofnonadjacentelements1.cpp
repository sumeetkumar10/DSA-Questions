#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n){
    vector<int> dp(n+1,0);

    dp[0]=arr[0];

    for(int i=1;i<n;i++){
        int excl=dp[i-1]+0;
        int incl=arr[i];
        if(i>=2){
            incl=dp[i-2]+arr[i];
        }

        dp[i]=max(excl,incl);
    }
    return dp[n-1];
}

int maxNonAdjacentSum(int arr[],int n){
    return solve(arr,n);
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