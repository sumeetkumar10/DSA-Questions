#include<iostream>
using namespace std;

bool isHappyNumber(int n){
    int sum=0;
    while(n!=0){
        int rem=n%10;
        sum+=rem*rem;
        n/=10;
    }

    if(sum==1){
        return true;
    }
    if(sum<7){
        return false;
    }
    return isHappyNumber(sum);
}

int main(){
    int n=20;

    if(isHappyNumber(n)){
        cout<<n<<" is A Happy Number."<<endl;
    }
    else{
        cout<<n<<" is not A Happy Number."<<endl;
    }

    return 0;
}