#include<iostream>
using namespace std;

bool linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int longestConsecutiveSequence(int arr[],int n){
    int longest=1;
    for(int i=0;i<n;i++){
        int key=arr[i];
        int count=1;
        while(linearSearch(arr,n,key+1)){
            key++;
            count++;
        }
        if(count>longest){
            longest=count;
        }
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