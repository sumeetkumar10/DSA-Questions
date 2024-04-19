#include<iostream>
using namespace std;

bool isSorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int arr[]={3,5,7,8,9};

    if(isSorted(arr,5)){
        cout<<"The array is sorted."<<endl;
    }
    else{
        cout<<"The array is not sorted."<<endl;
    }
    
    return 0;
}