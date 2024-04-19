#include<iostream>
#include<map>
using namespace std;

int countSubarrays(int arr[],int n,int k){
    int count=0;
    int xr=0;

    map<int,int> mp;
    mp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        int x=xr^k;
        count+=mp[x];
        mp[xr]++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the xor value"<<endl;
    cin>>k;

    cout<<"The number of subarrays with xor "<<k<<" is "<<countSubarrays(arr,n,k)<<endl;

    return 0;
}