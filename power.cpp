#include<iostream>
using namespace std;

long long int power(int n){
    if(n==0){
        return 1;
    }

    if(n==1){
        return 2;
    }

    long long int ans=power(n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return 2*ans*ans;
    }
}

int main(){
    int n=9;

    cout<<"2^"<<n<<" = "<<power(n)<<endl;

    return 0;
}