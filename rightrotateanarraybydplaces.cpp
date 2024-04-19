#include<iostream>
#include<vector>
using namespace std;

void rightRotate(int arr[],int n,int d){
    d%=n;
    vector<int> temp(d);

    if(d>n){
        return ;
    }

    for(int i=n-d;i<n;i++){
        temp[i-(n-d)]=arr[i];
    }

    for(int i=n-d-1;i>=0;i--){
        arr[i+d]=arr[i];
    }

    for(int i=0;i<d;i++){
        arr[i]=temp[i];
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

    int d;
    cout<<"Enter d"<<endl;
    cin>>d;

    printArray(arr,n);
    rightRotate(arr,n,d);
    printArray(arr,n);

    return 0;
}