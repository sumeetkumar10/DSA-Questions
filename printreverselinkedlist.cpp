#include<iostream>
#include<stack>
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

void reverse(Node* head)
{
    if (head == NULL){
        return ;
    }

    reverse(head->next);

    cout<<head->data<<" ";
}

// void reverse(Node* head){
//     Node* temp=head;

//     stack<int> st;
//     while(!st.empty()){
//         st.push(temp->data);
//         temp=temp->next;
//     }

//     while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
// }

int main(){
    Node* Node1=new Node(81);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,54);

    insertAtTail(tail,108);

    insertAtTail(tail,96);

    insertAtTail(tail,36);

    Print(head);
    reverse(head);

    return 0;
}