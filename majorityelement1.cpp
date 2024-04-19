#include<iostream>
#include<map>
using namespace std;

int majorityElement(int arr[],int n){
    map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        if(it.second>(n/2)){
            return it.first;
        }
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