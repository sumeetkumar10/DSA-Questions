#include <iostream>
#include <string>
using namespace std;

void printPermutation(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        int l = 6 - (i + j + k);
                        cout << str[i] << str[j] << str[k] << str[l] << endl;
                    }
                }
            }
        }
    }
}

int main()
{
    string str = "abcd";

    printPermutation(str);

    return 0;
}