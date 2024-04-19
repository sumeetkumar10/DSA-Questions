#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int longestConsecutiveSequence(int arr[],int n){
    if(n==0){
        return 0;
    }

    sort(arr,arr+n);
    int count=1,lastSmaller=arr[0],longest=1;

    for(int i=0;i<n;i++){
        if(arr[i]-1==lastSmaller){
            count+=1;
            lastSmaller=arr[i];
        }
        else if(lastSmaller!=arr[i]){
            count=1;
            lastSmaller=arr[i];
        }
        longest=max(longest,count);
    }
    return longest;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The longest consecutive sequence in the array is of "<<longestConsecutiveSequence(arr,n)<<" length."<<endl;

    return 0;
}