#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);

    tail->next=temp;

    tail=temp;
}

void Print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getNthNodeFromEnd(Node* &head,int n){
    Node* temp=head;
    int len=0;
    
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    if(len<n){
        return -1;
    }

    temp=head;
    for(int i=1;i<len-n+1;i++){
        temp=temp->next;
    }
    return temp->data;
}

int main(){
    Node* Node1=new Node(81);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,54);

    insertAtTail(tail,108);

    insertAtTail(tail,96);

    insertAtTail(tail,36);

    Print(head);

    int n=2;
    cout<<n<<"th node from the End of the Linked List is "<<getNthNodeFromEnd(head,n)<<endl;

    return 0;
}