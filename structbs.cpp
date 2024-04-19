#include<iostream>
using namespace std;

struct BS{
    int level[8];
    int yoe[8];
    string name[8]={"Sachin", "Dhoni" ,"Pat" ,"Cummins" ,"RK" ,"Yuvraj" ,"Surya" ,"Pandya"};
};

int firstOcc(int arr[],int n,int key){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int lastOcc(int arr[],int n,int key){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    BS arr1;

    for(int i=0;i<8;i++){
        cin>>arr1.level[i];
        cin>>arr1.yoe[i];
    }

    int key;
    cout<<"Enter The Level"<<endl;
    cin>>key;

    int first,last;
    first=firstOcc(arr1.level,8,key);
    last=lastOcc(arr1.level,8,key);
    cout<<first<<endl;
    cout<<last<<endl;
    cout<<"First person = "<<arr1.name[first]<<endl;
    cout<<"Last person = "<<arr1.name[last]<<endl;

    return 0;
}