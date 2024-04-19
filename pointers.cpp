#include<iostream>
using namespace std;

int main(){
    int num=99;

    cout<<num<<endl;
    int* ptr=&num;
    cout<<num<<endl;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<&num<<endl;

    return 0;
}