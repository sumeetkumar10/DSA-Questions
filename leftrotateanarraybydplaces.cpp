#include<iostream>
#include<vector>
using namespace std;

void leftRotate(int arr[],int n,int d){
    vector<int> temp;
    d%=n;

    for(int i=0;i<d;i++){
        temp.push_back(arr[i]);
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    int j=0;
    for(int i=n-d;i<n;i++){
        // arr[i]=temp[j++];
        arr[i]=temp[i-(n-d)];
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
    leftRotate(arr,n,d);
    printArray(arr,n);

    return 0;
}