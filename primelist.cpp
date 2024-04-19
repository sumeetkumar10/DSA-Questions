#include<iostream>
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

bool isPrime(int n){
    if(n<=1){
        return false;
    }

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

Node* primeList(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* curr=head;
    while(head!=NULL){
        int temp=head->data;
        if(isPrime(temp)){
            head=head->next;
            continue;
        }
        else{
            int temp2=temp;
            while(!isPrime(temp) && !isPrime(temp2)){
                temp++;
                temp2--;
            }

            if(isPrime(temp) && isPrime(temp2)){
                head->data=min(temp,temp2);
            }
            else if(isPrime(temp)){
                head->data=temp;
            }
            else if(isPrime(temp2)){
                head->data=temp2;
            }
        }
        head=head->next;
    }
    return curr;
}

int main(){
    Node* Node1=new Node(15);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,28);

    insertAtTail(tail,54);

    insertAtTail(tail,99);

    Print(head);
    Node* ans=primeList(head);
    Print(ans);

    return 0;
}