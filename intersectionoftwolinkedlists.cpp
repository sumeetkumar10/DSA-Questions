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

Node* intersectionOfSortedLists(Node* &head1,Node* &head2){
    Node* dummy=new Node(0);
    Node* curr=dummy;

    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
            Node* currNode=new Node(temp1->data);
            curr->next=currNode;
            curr=curr->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data<temp2->data){
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data){
            temp2=temp2->next;
        }
    }
    return dummy->next;
}

int main(){
    Node *Node1 = new Node(3);

    Node *head1 = Node1;
    Node *tail1 = Node1;

    insertAtTail(tail1, 6);

    insertAtTail(tail1, 9);

    Print(head1);

    Node *Node2 = new Node(1);

    Node *head2 = Node2;
    Node *tail2 = Node2;

    insertAtTail(tail2, 3);

    insertAtTail(tail2, 3);

    insertAtTail(tail2, 36);

    insertAtTail(tail2, 81);

    Print(head2);

    cout<<"The Intersection of the two Sorted linked lists"<<endl;
    Node* ans=intersectionOfSortedLists(head1,head2);
    Print(ans);

    return 0;
}