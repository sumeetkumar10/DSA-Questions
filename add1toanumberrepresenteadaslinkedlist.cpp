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

Node* reverse(Node* &head){
    Node* curr=head;
    Node* forward=NULL;
    Node* prev=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

Node* add(Node* &head){
    Node* newHead=reverse(head);
    Node* curr=newHead;
    Node* curr1=newHead;
    Node* prev=NULL;

    int carry=0;
    while(curr!=NULL){
        int sum=0;
        if(prev==NULL){
            sum=1+curr->data;
        }
        else{
            sum=carry+curr->data;
        }
        carry=sum/10;
        curr->data=sum%10;
        prev=curr;
        curr=curr->next;
    }
    if(carry==1){
        Node* newNode=new Node(1);
        prev->next=newNode;
    }
    return reverse(curr1);
}

int main(){
    Node* Node1=new Node(6);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,9);

    insertAtTail(tail,9);

    Print(head);

    cout<<"The sum after adding 1 to the number represented by the Linked List is "<<endl;
    Node* ans=add(head);
    Print(ans);

    return 0;
}