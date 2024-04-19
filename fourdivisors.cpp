#include<iostream>
#include<math.h>
using namespace std;

int sumFourDivisors(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        int count=0;
        int sumOfDivisors=0;
        int num=arr[i];
        for(int j=1;j<=sqrt(num);j++){
            if(num%j==0){
                if(j*j==num){
                    count++;
                    sumOfDivisors+=j;
                }
                else{
                    count+=2;
                    sumOfDivisors+=(j+num/j);
                }
            }
        }
        if(count==4){
            sum+=sumOfDivisors;
        }
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The sum of Four Divisors is "<<sumFourDivisors(arr,n)<<endl;

    return 0;
}