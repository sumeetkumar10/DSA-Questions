#include<iostream>
using namespace std;

int pivotIndex(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    int leftSum=0,rightSum=sum;
    for(int i=0;i<n;i++){
        rightSum-=arr[i];
        if(leftSum==rightSum) return i;
        leftSum+=arr[i];
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"The pivot Index In the array is "<<pivotIndex(arr,n)<<endl;

    return 0;
}