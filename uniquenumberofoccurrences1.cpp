#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool uniqueOccurrences(int arr[],int n){
    unordered_map<int,int> map;
    unordered_set<int> set;

    for(int i=0;i<n;i++) map[arr[i]]++;

    for(auto it:map){
        if(!set.insert(it.second).second) return false;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    if(uniqueOccurrences(arr,n))
        cout<<"The array has unique Number of Occurrences."<<endl;
    else
        cout<<"The array does not have unique Number of Occurrences."<<endl;

    return 0;
}