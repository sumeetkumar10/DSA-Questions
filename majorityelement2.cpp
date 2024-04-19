#include<iostream>
#include<map>
using namespace std;

int majorityElement(int arr[],int n){
    int count=0;
    int ele;
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            ele=arr[i];
        }
        else if(ele==arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            count1++;
        }
    }
    if(count1>(n/2)){
        return ele;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Majority Element in the array is "<<majorityElement(arr,n)<<endl;

    return 0;
}