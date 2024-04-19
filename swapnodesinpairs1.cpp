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

Node* swapPairs(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* curr=head->next->next;
    Node* prev=head;
    head=head->next;
    head->next=prev;

    while(curr!=NULL && curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
        Node* temp=curr->next->next;
        curr->next->next=curr;
        curr=temp;
    }
    prev->next=curr;
    return head;
}

int main(){
    Node* Node1=new Node(3);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,6);

    insertAtTail(tail,9);

    insertAtTail(tail,36);

    insertAtTail(tail,81);

    Print(head);

    Node* ans=swapPairs(head);
    Print(ans);

    return 0;
}