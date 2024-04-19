#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int start=0;
    int end=n-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) end=mid-1;
        else start=mid+1;
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int arr[]={96,99,102,114,120};

    int n=5;

    int target=120;

    cout<<target<<" is present at "<<binarySearch(arr,n,target)<<" index in the array."<<endl;

    return 0;
}