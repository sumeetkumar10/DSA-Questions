#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot=start;
    int i=start;
    int j=end;

    while(i<j){
        while(arr[i]<=arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[pivot]);
    return j;
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