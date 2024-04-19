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

Node *removeNthNodeFromEnd(Node *&head, int n)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == n)
    {
        head = head->next;
        return head;
    }
    temp = head;
    n = count - n - 1;
    count = 0;
    while (temp!=NULL)
    {
        if (count == n)
        {
            temp->next = temp->next->next;
        }
        count++;
        temp = temp->next;
    }
    return head;
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

    int n = 2;
    Node *ans = removeNthNodeFromEnd(head, n);
    Print(ans);

    return 0;
}