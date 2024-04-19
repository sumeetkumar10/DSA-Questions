#include<iostream>
#include<vector>
using namespace std;

int solve(int* arr){
    int prev2=0;
    int prev1=arr[0];

    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++){
        int excl=prev1+0;
        int incl=arr[i];
        if(i>=2){
            incl=prev2+arr[i];
        }

        int ans=max(excl,incl);

        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int houseRobber(int arr[],int n){
    int first[n-1],second[n-1];

    if(n==1){
        return arr[0];
    }

    for(int i=0;i<n;i++){
        if(i!=n-1){
            first[i]=arr[i];
        }
        if(i!=0){
            second[i]=arr[i];
        }
    }

    return max(solve(first),solve(second));
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Maximum Sum of non-adjacent elements is "<<houseRobber(arr,n)<<endl;

    return 0;
}