#include<iostream>
#include<vector>
using namespace std;

void moveZeros(int arr[],int n){
    vector<int> temp;

    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }

    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }

    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={5,-4,0,-1,0,2,3,0};

    int n=8;

    printArray(arr,n);
    moveZeros(arr,n);
    printArray(arr,n);

    return 0;
}