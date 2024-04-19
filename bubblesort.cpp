#include<iostream>
using namespace std;

struct Student{
    string name="SUMEET SHARMA";
    int rollNo=84;
    char group='Y';
};


// void bubbleSort(int arr[],int n){
//     for(int i=n-1;i>=1;i--){
//         bool flag=false;
//         for(int j=0;j<=i-1;j++){
//             if(arr[j+1]<arr[j]){
//                 int temp=arr[j+1];
//                 arr[j+1]=arr[j];
//                 arr[j]=temp;
//                 flag=true;
//             }
//         }
//         if(flag==false){
//             break;
//         }
//     }
// }

void bubbleSort(struct Student student[],int n){
    for(int i=n-1;i>=1;i--){
        // bool flag=false;
        int swapCount=0;
        for(int j=0;j<=i-1;j++){
            if(student[j+1].rollNo<student[j].rollNo){
                struct Student temp=student[j+1];
                student[j+1]=student[j];
                student[j]=temp;
                // flag=true;
                swapCount++;
            }
        }
        // if(flag==false){
        //     break;
        // }
        if(swapCount==0){
            break;
        }
    }
}

// void printArray(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

void printArray(struct Student student[],int n){
    for(int i=0;i<n;i++){
        cout<<student[i].rollNo<<" ";
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
    // bubbleSort(arr,n);
    // printArray(arr,n);

    // struct Student student1;
    // student1.rollNo=96;

    // struct Student student2;
    // student2.rollNo=99;

    // struct Student student3;
    // student3.rollNo=102;

    struct Student studentarr[3];
    for(int i=0;i<3;i++){
        cin>>studentarr[i].rollNo;
    }

    printArray(studentarr,3);
    bubbleSort(studentarr,3);
    printArray(studentarr,3);

    return 0;
}