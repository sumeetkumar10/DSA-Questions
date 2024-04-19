#include<iostream>
using namespace std;

void reverse(int arr[],int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }
}

void rightRotate(int arr[],int n,int d){
    d%=n;
    reverse(arr,n-d,n-1);
    reverse(arr,0,n-d-1);
    reverse(arr,0,n-1);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cout<<"Enter d"<<endl;
    cin>>d;

    printArray(arr,n);
    rightRotate(arr,n,d);
    printArray(arr,n);

    return 0;
}