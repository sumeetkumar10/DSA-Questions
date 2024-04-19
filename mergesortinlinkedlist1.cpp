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
    
    Node* fast=head->next;
    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* merge(Node* &first,Node* &second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    Node* ans=new Node(-1);
    Node* temp=ans;

    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            temp->next=first;
            temp=first;
            first=first->next;
        }
        else{
            temp->next=second;
            temp=second;
            second=second->next;
        }
    }
    while(first!=NULL){
        temp->next=first;
        temp=first;
        first=first->next;
    }
    while(second!=NULL){
        temp->next=second;
        temp=second;
        second=second->next;
    }
    return ans->next;
}

Node* mergeSort(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* middle=getMiddle(head);

    Node* left=head;
    Node* right=middle->next;

    middle->next=NULL;

    left=mergeSort(left);
    right=mergeSort(right);

    Node* ans=merge(left,right);
    return ans;
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

    cout<<"The sorted Linked List is "<<endl;
    Node* ans=mergeSort(head);
    Print(ans);

    return 0;
}