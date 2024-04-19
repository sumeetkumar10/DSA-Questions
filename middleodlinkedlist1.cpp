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

Node* getMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node* Node1=new Node(144);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,225);

    insertAtTail(tail,180);

    insertAtTail(tail,324);

    Print(head);

    cout<<"The middle node of the Linked List is "<<getMiddle(head)->data<<endl;

    return 0;
}