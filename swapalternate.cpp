#include<iostream>
using namespace std;

void swapAlternate(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if((i+1)<n){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
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

    printArray(arr,n);
    swapAlternate(arr,n);
    printArray(arr,n);

    return 0;
}