#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number you want to search in the array"<<endl;
    cin>>key;

    cout<<key<<" is present at "<<binarySearch(arr,n,key)<<" index in the array."<<endl;

    return 0;
}