#include<iostream>
#include<unordered_set>
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

Node* removeDuplicates(Node* &head){
    Node* curr=head;

    unordered_set<int> seen;

    if(curr==NULL){
        return head;
    }
    else{
        seen.insert(curr->data);
    }

    while(curr!=NULL && curr->next!=NULL){
        if(seen.find(curr->next->data)!=seen.end()){
            curr->next=curr->next->next;
        }
        else{
            seen.insert(curr->next->data);
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node *Node1 = new Node(3);

    Node *head = Node1;
    Node *tail = Node1;

    insertAtTail(tail, 6);

    insertAtTail(tail, 9);

    insertAtTail(tail, 6);

    insertAtTail(tail, 3);

    Print(head);

    Node* ans=removeDuplicates(head);
    Print(ans);

    return 0;
}