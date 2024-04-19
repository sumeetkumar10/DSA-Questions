#include<iostream>
#include<climits>
using namespace std;

int findMaximum(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}

int findMinimum(int arr[],int n){
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return mini;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum element in the array is "<<findMaximum(arr,n)<<endl;
    cout<<"The minimum element in the array is "<<findMinimum(arr,n)<<endl;

    return 0;
}