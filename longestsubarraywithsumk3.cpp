#include<iostream>
using namespace std;

int longestSubarray(int arr[],int n,int k){
    int maxLen=0;
    int left=0;
    int right=0;
    int sum=arr[0];

    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }

        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }

        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return maxLen;
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
    cout<<"Enter k"<<endl;
    cin>>k;

    cout<<"The length of the longest subarray with sum "<<k<<" is "<<longestSubarray(arr,n,k)<<endl;

    return 0;
}