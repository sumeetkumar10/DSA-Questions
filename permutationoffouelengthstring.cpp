#include<iostream>
#include<string>
using namespace std;

void printPermutation(string str){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                for (int k = 0; k < 4; k++) {
                    if (k != i && k != j) {
                        for (int l = 0; l < 4; l++) {
                            if (l != i && l != j && l != k) {
                                cout<< str[i] << str[j] << str[k] << str[l]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    string str = "abcd";

    printPermutation(str);

    return 0;
}
