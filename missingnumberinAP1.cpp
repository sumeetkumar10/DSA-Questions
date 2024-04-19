#include<iostream>
using namespace std;

int missingNumberInAP(int* arr,int n){
    int d=(arr[n-1]-arr[0])/n;

    int missing=-1;
    for(int i=0;i<n;i++){
        int diff=arr[i+1]-arr[i];

        if(diff!=d){
            missing=arr[i]+d;
            break;
        }
    }
    return missing;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The missing number in the AP is "<<missingNumberInAP(arr,n)<<endl;

    return 0;
}