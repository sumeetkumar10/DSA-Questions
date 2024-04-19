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

Node* deleteMiddle(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        return NULL;
    }

    Node* prev=NULL;
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    prev->next=slow->next;
    return head;
}

int main(){
    Node* Node1=new Node(144);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,225);

    insertAtTail(tail,180);

    insertAtTail(tail,324);

    Print(head);

    cout<<"The Linked List after deleting the middle element is "<<endl;
    Node* ans=deleteMiddle(head);
    Print(ans);

    return 0;
}