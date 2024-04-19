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

// int getNthNodeFromEnd(Node *head, int n)
// {
//     if (head == NULL || n <= 0)
//     {
//         return -1;
//     }

//     Node *slow = head;
//     Node *fast = head;

//     for (int i = 0; i < n; i++)
//     {
//         if (fast == NULL)
//         {
//             return -1;
//         }
//         fast = fast->next;
//     }

//     while (fast != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }

//     return slow->data;
// }

void printNthNodeFromEnd(Node* head, int n)
{
    if (head == NULL){
        return ;
    }

    static int i = 0;

    printNthNodeFromEnd(head->next, n);

    if (++i == n){
        cout << head->data;
    }
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
    // cout << n << "th node from the End of the Linked List is " << getNthNodeFromEnd(head, n) << endl;

    printNthNodeFromEnd(head,n);

    return 0;
}