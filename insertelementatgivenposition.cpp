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

Node* insertNode(Node* &head,int ele,int k){
    if(head==NULL){
        if(k==1){
            return new Node(ele);
        }
        else{
            return head;
        }
    }

    Node* temp=new Node(ele);
    if(k==1){
        temp->next=head;
        return head;
    }

    int count=0;
    temp=head;

    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* x=new Node(ele);
            temp->next=x;
            break;
        }
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

    int ele=108;
    int x=3;
    Node* ans=insertNode(head,ele,x);
    Print(ans);

    return 0;
}