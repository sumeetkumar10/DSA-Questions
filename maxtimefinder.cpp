#include<iostream>
using namespace std;

pair<string,string> findMaxTime(int nums[]) {
        int maxHour = -1;
        int maxMinute = -1;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i != j && i != k && j != k) {
                        int hour = nums[i] * 10 + nums[j];
                        int minute = nums[k] * 10 + nums[6 - i - j - k];

                        if (hour < 24 && minute < 60 && (hour > maxHour || (hour == maxHour && minute > maxMinute))) {
                            maxHour = hour;
                            maxMinute = minute;
                        }
                    }
                }
            }
        }

        pair<string,string> ans;
        if (maxHour != -1 && maxMinute != -1) {
            ans.first=to_string(maxHour);
            ans.second=to_string(maxMinute);
        }
        else {
            ans.first="-1";
            ans.second="-1";
        }
        return ans;
    }

int main(){
        int* arr = new int[4];
        for (int i = 0; i < 4; i++) {
            cin>>arr[i];
        }

        pair<string,string> maxTime = findMaxTime(arr);

        if(maxTime.first!="-1" && maxTime.second!="-1") {
            cout<<"The maximum time that can be generated is: " << maxTime.first<<" "<<maxTime.second<<endl;
        } 
        else {
            cout<<"Invalid input. Please Type valid Input"<<endl;
        }

    return 0;
}