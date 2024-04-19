#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n=12;

    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n%2;  // Use modulo operation to get the remainder
        ans=(bit*pow(10,i))+ans;
        n=n/2;       // Divide the number by 2 to get the next bit
        i++;
    }

    cout<<"Equivalent Binary Form is "<<ans<<endl;

    return 0;
}