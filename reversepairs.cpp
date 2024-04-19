#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums,int start,int end){
    int mid=start+(end-start)/2;
    
    int len1=mid-start+1;
    int len2=end-mid;

    int arr1[len1];
    int arr2[len2];

    int k=start;
    for(int i=0;i<len1;i++){
        arr1[i]=nums[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=nums[k++];
    }

    int i=0,j=0;
    k=start;
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            nums[k++]=arr1[i++];
        }
        else{
            nums[k++]=arr2[j++];
        }
    }
    while(i<len1){
        nums[k++]=arr1[i++];
    }
    while(j<len2){
        nums[k++]=arr2[j++];
    }
}

int countPairs(vector<int>& nums,int start,int mid,int end){
    int right=mid+1,count=0;
    for(int i=start;i<=mid;i++){
        if(right<=end && nums[i]>2*nums[right]){
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}

int mergeSort(vector<int>& nums,int start,int end){
    int mid=start+(end-start)/2;

    int count=0;
    if(start>=end){
        return count;
    }

    count+=mergeSort(nums,start,mid);
    count+=mergeSort(nums,mid+1,end);
    count+=countPairs(nums,start,mid,end);
    merge(nums,start,end);

    return count;
}

int main(){
    vector<int> nums={1,3,2,3,1};

    int n=nums.size();

    cout<<"The number of Reverse Pairs is "<<mergeSort(nums,0,n-1)<<endl;

    return 0;
}