#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZerosToEnd(vector<int>& arr,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }

    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }

    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
    return arr;
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int a;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }

    vector<int> ans=moveZerosToEnd(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}