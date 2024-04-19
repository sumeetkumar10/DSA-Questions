#include<iostream>
#include<climits>
using namespace std;

int maxSubarraySum(int arr[],int n){
    int maxi=INT_MIN;
    int sum=0;

    int start=0;
    int ansStart=-1;
    int ansEnd=-1;

    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }

        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;

            ansStart=start;
            ansEnd=i;
        }

        if(sum<0){
            sum=0;
        }

        if(maxi<0){
            maxi=0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return maxi;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    maxSubarraySum(arr,n);

    return 0;
}