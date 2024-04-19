#include<iostream>
using namespace std;

int findPeak(int arr[],int n){
    int start=0;
    int end=n-1;

    while(start<end){
        int mid=start+(end-start)/2;

        if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int findAgnosticOrder(int target,int arr[],int n,int start,int end){
    bool asc=arr[start]<arr[end];

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(asc){
            if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(arr[mid]>target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int findMountainArray(int arr[],int n,int target){
    int peak=findPeak(arr,n);
    int order=findAgnosticOrder(target,arr,n,0,peak);
    if(order!=-1){
        return order;
    }
    return findAgnosticOrder(target,arr,n,peak+1,n-1);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;

    cout<<target<<" is present at "<<findMountainArray(arr,n,target)<<" index in the array."<<endl;

    return 0;
}