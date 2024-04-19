#include<iostream>
#include<climits>
using namespace std;

int maxSubarraySum(int arr[],int n){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum>maxSum){
                maxSum=sum;
            }
        }
    }
    return maxSum;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum Subarray Sum is "<<maxSubarraySum(arr,n)<<endl;

    return 0;
}