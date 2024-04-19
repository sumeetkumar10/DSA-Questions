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

Node* rotate(Node* head){
    Node* curr=head;

    while(curr->next->next!=NULL){
        curr=curr->next;
    }

    Node* newHead=curr->next;
    newHead->next=head;
    curr->next=NULL;

    return newHead;
}

int getLength(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* rotateList(Node* head,int k){
    if(head==NULL || head->next==NULL || k==0){
        return head;
    }

    int len=getLength(head);

    Node* curr=head;
    int count=0;

    k%=len;
    while(count<k){
        curr=rotate(curr);
        count++;
    }
    return curr;
}

int main(){
    Node* Node1=new Node(0);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,3);

    insertAtTail(tail,6);

    insertAtTail(tail,9);

    insertAtTail(tail,12);

    insertAtTail(tail,15);

    Print(head);

    int k=3;
    Node* ans=rotateList(head,k);
    Print(ans);

    return 0;
}