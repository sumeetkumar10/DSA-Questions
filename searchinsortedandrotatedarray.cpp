#include<iostream>
using namespace std;

int findPivot(int arr[],int n){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int binarySearch(int arr[],int n,int start,int end,int key){
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
    cout<<"Enter the number you wat to search in the array"<<endl;
    cin>>key;

    int pivot=findPivot(arr,n);
    if(key>=arr[pivot] && key<=arr[n-1]){
        cout<<key<<" is present at "<<binarySearch(arr,n,pivot,n-1,key)<<" index in the array."<<endl;
    }
    else{
        cout<<key<<" is present at "<<binarySearch(arr,n,0,pivot-1,key)<<" index in the array."<<endl;
    }

    return 0;
}