#include<iostream>
#include<map>
using namespace std;

int longestSubarray(int arr[],int n,int k){
    int maxLen=0;
    map<int,int> presumMap;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==k){
            maxLen=max(maxLen,i+1);
        }

        int rem=sum-k;
        if(presumMap.find(rem)!=presumMap.end()){
            int len=i-presumMap[rem];
            maxLen=max(maxLen,len);
        }

        if(presumMap.find(sum)==presumMap.end()){//Without this, it will fail for Test Cases having one or more 0s in the subarray. So, if the sum already exists we need to update it again.
            presumMap[sum]=i;
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