#include<iostream>
using namespace std;

int peakIndex(int arr[],int n){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid+1]>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The peak index in the array is "<<peakIndex(arr,n)<<endl;

    return 0;
}