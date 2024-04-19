#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[],int n){
    sort(arr,arr+n);
    int d=(arr[n-1]-arr[0])/n;

    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    int missing=-1;
    while(start<=end){
        if(arr[mid+1]-arr[mid]!=d){
            missing=arr[mid]+d;
            break;
        }
        else if(mid>0 && arr[mid]-arr[mid-1]!=d){
            missing=arr[mid-1]+d;
            break;
        }
        else if(arr[mid]==arr[0]+mid*d){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return missing;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The missing number in the AP is "<<missingNumber(arr,n)<<endl;

    return 0;
}