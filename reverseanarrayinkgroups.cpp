#include<iostream>
using namespace std;

void reverseArray(int arr[],int n,int k){
    for(int i=0;i<n;i+=k){
        int start=i;
        int end=min(i+k-1,n-1);

        while(start<=end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;

            start++;
            end--;
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

    int k;
    cout<<"Enter k"<<endl;
    cin>>k;

    printArray(arr,n);
    reverseArray(arr,n,k);
    printArray(arr,n);

    return 0;
}