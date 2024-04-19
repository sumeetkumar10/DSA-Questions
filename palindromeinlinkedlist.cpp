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

Node* getMiddle(Node* &head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        return head;
    }

    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

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

bool isPalindrome(Node* &head){
    if(head==NULL){
        return true;
    }

    Node* middle=getMiddle(head);
    Node* curr=head;
    Node* last=reverse(middle->next);

    while(last!=NULL){
        if(curr->data!=last->data){
            return false;
        }
        curr=curr->next;
        last=last->next;
    }
    return true;
}

int main(){
    Node* Node1=new Node(3);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,6);

    insertAtTail(tail,9);

    insertAtTail(tail,6);

    insertAtTail(tail,3);

    Print(head);

    if(isPalindrome(head)){
        cout<<"The Linked List is palindrome."<<endl;
    }
    else{
        cout<<"The Linked List is not palindrome."<<endl;
    }

    return 0;
}