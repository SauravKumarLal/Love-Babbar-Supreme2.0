#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL; //current node k prev & next ko null mark kar dena
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

void Print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<< "->";
        temp = temp->next;
    }
    cout<<endl;
}

int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        // newNode->next = NULL;
        // newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = head->prev; //head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
}

int main(){
    // Node* head = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 44);
    insertAtHead(head, tail, 33);
    insertAtHead(head, tail, 22);
    insertAtHead(head, tail, 11);
    Print(head);
}