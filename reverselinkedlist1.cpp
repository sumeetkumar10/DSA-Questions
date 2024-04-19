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

void solve(Node* &head,Node* curr,Node* prev){
    if(curr==NULL){
        head=prev;
        return ;
    }

    Node* forward=curr->next;
    solve(head,forward,curr);
    curr->next=prev;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    solve(head,curr,prev);
    return head;
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

    Node* ans=reverse(head);
    Print(ans);

    return 0;
}