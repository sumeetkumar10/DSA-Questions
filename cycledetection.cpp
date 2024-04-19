#include <iostream>
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

Node* floydCycleDetect(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* fast=head;
    Node* slow=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getIntersectionPoint(Node* &head){
    Node* slow=head;
    Node* intersection=floydCycleDetect(head);

    if(head==NULL){
        return NULL;
    }
    if(intersection==NULL){
        return NULL;
    }

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head==NULL){
        return ;
    }

    Node* startOfLoop=getIntersectionPoint(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main()
{
    Node *Node1 = new Node(81);

    Node *head = Node1;
    Node *tail = Node1;

    insertAtTail(tail, 54);

    insertAtTail(tail, 108);

    insertAtTail(tail, 96);

    insertAtTail(tail, 36);

    Print(head);

    tail->next=head->next->next;

    if(floydCycleDetect(head)!=NULL){
        cout<<"Cycle is present in the Linked List."<<endl;
    }
    else{
        cout<<"Cycle is not present in the Linked List."<<endl;
    }

    cout<<"Cycle is intersecting at "<<getIntersectionPoint(head)->data<<" point in the Linked List."<<endl;

    removeLoop(head);
    Print(head);

    if(floydCycleDetect(head)!=NULL){
        cout<<"Cycle is present in the Linked List."<<endl;
    }
    else{
        cout<<"Cycle is not present in the Linked List."<<endl;
    }

    return 0;
}