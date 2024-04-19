#include<iostream>
using namespace std;

struct Student{
    string name="SUMEET";
    int rollNo=84;
    char group;
};

// void selectionSort(int* arr,int n){
//     for(int i=0;i<=n-2;i++){
//         int mini=i;                   //Find the smallest element in the array and put in the first place.
//         for(int j=i;j<=n-1;j++){
//             if(arr[j]<arr[mini]){
//                 mini=j;
//             }
//         }
//         int temp=arr[i];
//         arr[i]=arr[mini];
//         arr[mini]=temp;
//     }
// }

void selectionSort(struct Student student[],int n){
    int countSwaps=0;
    int count=0;
    for(int i=0;i<=n-2;i++){
        int mini=i;                   //Find the smallest element in the array and put in the first place.
        for(int j=i;j<=n-1;j++){
            if(student[j].rollNo<student[mini].rollNo){
                countSwaps++;
                mini=j;
            }
        }
        int temp=student[i].rollNo;
        student[i]=student[mini];
        student[mini].rollNo=temp;
        count++;
    }
    cout<<countSwaps<<endl;
    cout<<count<<endl;
}

void printArray(struct Student student[],int n){
    for(int i=0;i<n;i++){
        cout<<student[i].name<<" ";
        cout<<student[i].rollNo<<" ";
        cout<<student[i].group<<" ";
    }
    cout<<endl;
}

int main(){
    // int n;
    // cout<<"Enter the size of the array you want to create"<<endl;
    // cin>>n;

    // int* arr=new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // printArray(arr,n);
    // selectionSort(arr,n);
    // printArray(arr,n);



    struct Student studentarr[3];
    // for(int i=0;i<3;i++){
    //     cin>>studentarr[i].rollNo;
    // }

    studentarr[0].name="VIVEK";
    studentarr[0].rollNo=97;
    studentarr[0].group='Y';

    studentarr[1].name="SUMEET";
    studentarr[1].rollNo=84;
    studentarr[1].group='Y';

    studentarr[2].name="VIVEK";
    studentarr[2].rollNo=93;
    studentarr[2].group='Y';

    printArray(studentarr,3);
    selectionSort(studentarr,3);
    printArray(studentarr,3);

    return 0;
}