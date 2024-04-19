#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int key){
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

// void insertionSort(int arr[],int n){
//     for(int i=0;i<=n-1;i++){
//         int j=i;
//         while(j>0 && arr[j-1]>arr[j]){
//             int temp=arr[j-1];
//             arr[j-1]=arr[j];
//             arr[j]=temp;

//             j--;
//         }
//     }
// }

void insertionSort(int arr[],int n){
    int comp=0;
    int swaps=0;
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        int search=binarySearch(arr,0,j,key);
        // arr[j+1]=arr[j];
        while(j>=search){
            arr[j+1]=arr[j];
            comp++;
            j--;
        }
        arr[j+1]=key;
        swaps++;
    }
    cout<<"Comparison = "<<comp<<" , "<<"Swaps = "<<swaps<<endl;
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // int n;
    // cout<<"Enter the size of the array you want to create"<<endl;
    // cin>>n;

    // int* arr=new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    int arr[]={4,9,7,6,3,36,81,96,99};
    int n=9;

    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);

    return 0;
}