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

Node* intersectionOfTwoLinkedLists(Node* &head1,Node* &head2){
    while(head1!=NULL){
        Node* temp=head2;
        while(temp!=NULL){
            if(temp==head1){
                return head1;
            }
            temp=temp->next;
        }
        head1=head1->next;
    }
    return NULL;
}

int main(){
    Node *Node1 = new Node(1);

    Node *head1 = Node1;
    Node *tail1 = Node1;

    insertAtTail(tail1,3);

    insertAtTail(tail1, 1);

    insertAtTail(tail1, 2);

    insertAtTail(tail1,4);

    Print(head1);

    Node *Node2 = new Node(3);

    Node *head2 = Node2;
    Node *tail2 = Node2;

    insertAtTail(tail2, 2);

    insertAtTail(tail2, 4);

    Print(head2);

    Node* ans=intersectionOfTwoLinkedLists(head1,head2);
    if(ans==NULL){
        cout<<"There is no intersection point in the Linked Lists."<<endl;
    }
    else{
        cout<<"The two Linked Lists are intersectiong at "<<ans->data<<" node."<<endl;
    }

    return 0;
}