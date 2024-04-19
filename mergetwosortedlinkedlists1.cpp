#include <iostream>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;

    tail = temp;
}

void Print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeTwoSortedLists(Node* &first,Node* &second){
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
    ans=ans->next;
    return ans;
}

int main()
{
    Node *Node1 = new Node(3);

    Node *head1 = Node1;
    Node *tail1 = Node1;

    insertAtTail(tail1, 6);

    insertAtTail(tail1, 9);

    Print(head1);

    Node *Node2 = new Node(1);

    Node *head2 = Node2;
    Node *tail2 = Node2;

    insertAtTail(tail2, 2);

    insertAtTail(tail2, 5);

    insertAtTail(tail2, 7);

    insertAtTail(tail2, 15);

    Print(head2);

    cout<<"The Linked List after merging the two sorted Linked Lists is "<<endl;
    Node* ans=mergeTwoSortedLists(head1,head2);
    Print(ans);

    return 0;
}