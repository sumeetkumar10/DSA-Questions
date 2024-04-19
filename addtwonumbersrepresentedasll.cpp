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

void insert(Node* &head,Node* &tail,int digit){
    Node* temp=new Node(digit);

    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* &first,Node* &second){
    int carry=0;

    Node* ansHead=NULL;
    Node* ansTail=NULL;

    while(first!=NULL && second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        insert(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insert(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insert(ansHead,ansTail,digit);
        carry=sum/10;
        second=second->next;
    }
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        insert(ansHead,ansTail,digit);
        carry=sum/10;
    }
    return ansHead;
}

Node* add2Lists(Node* first,Node* second){
    first=reverse(first);
    second=reverse(second);

    Node* ans=add(first,second);
    ans=reverse(ans);
    return ans;
}

int main()
{
    Node *Node1 = new Node(6);

    Node *head1 = Node1;
    Node *tail1 = Node1;

    insertAtTail(tail1, 9);

    insertAtTail(tail1, 3);

    Print(head1);

    Node *Node2 = new Node(3);

    Node *head2 = Node2;
    Node *tail2 = Node2;

    insertAtTail(tail2, 6);

    insertAtTail(tail2, 9);

    Print(head2);

    Node* ans=add2Lists(head1,head2);
    cout<<"The sum of the two Linked Lists is "<<endl;
    Print(ans);

    return 0;
}