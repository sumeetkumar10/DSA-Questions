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

bool detectCycle(Node* &head){
    Node* temp=head;
    map<Node*,bool> visited;

    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }

        visited[temp]=true;
        temp=temp->next;
    }
    return false;
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

    tail->next=head;
    if(detectCycle(head)){
        cout<<"Cycle is present in the Linked List."<<endl;
    }
    else{
        cout<<"Cycle is not present in the Linked List."<<endl;
    }

    return 0;
}