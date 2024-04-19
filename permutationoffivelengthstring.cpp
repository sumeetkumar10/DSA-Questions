#include<iostream>
#include<string>
using namespace std;

void printPermutation(string str){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != i) {
                for (int k = 0; k < 5; k++) {
                    if (k != i && k != j) {
                        for (int l = 0; l < 5; l++) {
                            if(l!=i && l!=j && l!=k){
                                for(int m=0;m<5;m++){
                                    if(m!=i && m!=j && m!=k && m!=l){
                                        cout<<str[i]<<str[j]<<str[k]<<str[l]<<str[m]<<endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    string str = "abcde";

    printPermutation(str);

    return 0;
}