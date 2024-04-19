#include<iostream>
using namespace std;

void merge(int arr[],int start,int end,int mid){
    int start2=mid+1;

    if(arr[start2]>=arr[mid]){
        return ;
    }

    while(start<=mid && start2<=end){
        if(arr[start]<=arr[start2]){
            start++;
        }
        else{
            int value=arr[start2];
            int index=start2;

            while(index!=start){
                arr[index]=arr[index-1];
                index--;
            }
            arr[index]=value;

            start++;
            start2++;
            mid++;
        }
    }
}

void mergeSort(int arr[],int start,int end,int n){
    int mid=start+(end-start)/2;

    if(start>=end){
        return ;
    }

    mergeSort(arr,start,mid,n);
    mergeSort(arr,mid+1,end,n);
    merge(arr,start,end,mid);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={3,6,9,18,15};

    int n=5;

    printArray(arr,n);
    mergeSort(arr,0,n-1,n);
    printArray(arr,n);

    return 0;
}