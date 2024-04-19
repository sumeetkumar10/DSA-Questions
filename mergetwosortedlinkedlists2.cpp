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
    Node* head=new Node(0);
    Node* curr=head;

    while(first!=NULL && second!=NULL){
        if(first->data<=second->data){
            curr->next=first;
            first=first->next;
        }
        else{
            curr->next=second;
            second=second->next;
        }
        curr=curr->next;
    }
    if(first!=NULL){
        curr->next=first;
    }
    if(second!=NULL){
        curr->next=second;
    }
    return head->next;
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