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

Node* deleteNode(Node* &head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }

    if(k==1){
        head=head->next;
        return head;
    }

    int count=0;
    Node* temp=head;
    Node* prev=NULL;

    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    Node* Node1=new Node(99);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,96);

    insertAtTail(tail,93);

    insertAtTail(tail,102);

    insertAtTail(tail,144);

    Print(head);

    int k=3;
    Node* ans=deleteNode(head,k);
    Print(ans);

    return 0;
}