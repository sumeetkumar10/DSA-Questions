#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivotIndex=start;
    int pivotElement=arr[pivotIndex];

    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }

    int rightIndex=start+count;
    
    swap(arr[pivotIndex],arr[rightIndex]);
    
    pivotIndex=rightIndex;

    int i=start;
    int j=end;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int start,int end){
    if(start>=end){
        return ;
    }

    int p=partition(arr,start,end);

    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
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

    quickSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}