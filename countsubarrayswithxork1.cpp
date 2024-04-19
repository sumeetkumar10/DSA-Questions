#include<iostream>
#include<map>
using namespace std;

int countSubarrays(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr=xr^arr[j];
            if(xr==k){
                count++;
            }
        }
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