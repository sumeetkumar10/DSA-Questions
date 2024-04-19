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

Node* reverseKGroups(Node* head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* curr=head;
    Node* forward=NULL;
    Node* prev=NULL;
    int count=0;

    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=reverseKGroups(forward,k);
    }
    return prev;
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

    int k=3;

    Node* ans=reverseKGroups(head,k);
    Print(ans);

    return 0;
}