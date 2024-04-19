#include<iostream>
using namespace std;

void mergeTwoSortedArrays(int* arr1,int n,int* arr2,int m,int* arr3){
    int i=0,j=0,k=0;
    
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr3[k++]=arr1[i++];
    }
    while(j<m){
        arr3[k++]=arr2[j++];
    }
}

void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the first array you want to create"<<endl;
    cin>>n;

    int* arr1=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter the size of the second array you want to create"<<endl;
    cin>>m;

    int* arr2=new int[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    int* arr3=new int[n+m];
    mergeTwoSortedArrays(arr1,n,arr2,m,arr3);
    for(int i=0;i<(n+m);i++){
        cout<<arr3[i]<<" ";
    }


    return 0;
}