#include<iostream>
using namespace std;

void transpose(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=i+1;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    transpose(arr);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}