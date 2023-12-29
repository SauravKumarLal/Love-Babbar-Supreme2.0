//deletion from linkedList

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        // cout<<"Inside default ctor"<<endl;
        this->next = NULL;
    }

    Node(int data)
    {
        // cout<<"Inside parameterized ctor"<<endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout<<"Destructor called for: "<<this->next<<endl;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void numberOfNode(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Number of node: " << count << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{ // pass by reference, pass by value won't work
    if (head == NULL)
    {
        // empty LL
        // Step1: create node
        Node *newNode = new Node(data);

        // Step2: Update head
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non-empty LL
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1: creatae a node
        Node *newNode = new Node(data);
        // step2: connect woth tail ndoe
        tail->next = newNode;
        // step3: update tail;
        tail = newNode;
    }
}

void findLength(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    int len = findLength(head);

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    else if (position > len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);

        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }

        // step3:
        newNode->next = curr;

        // step4:
        prev->next = newNode;
    }
}



void deleteNode(Node* &head, Node* &tail, int position){
    //empty list
    int len = findLength(head);
    if(head == NULL){
        cout<<"Not possible as LL is empty!"<<endl;
        return;
    }

    //delete from head
    else if (position == 1){
        //delete first node
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else if(position == len){
        //last node ko delete kardo
        //traverse kar k second last node tak aana hao
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }

    else{
        //delete a node in the middle of LL 
        Node* curr = head;
        while(curr->next != position){
            curr = curr->next;
        }
        curr
    }
    

}
int main()
{
    // Node n;
    // Node* head = new Node();
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);
    // Node *tail = fifth;

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // // Linked List created
    // Node *head = first;
    // printLL(head);
    // numberOfNode(head);
    // insertAtHead(head, tail, 7);
    // printLL(head);

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    print(head);
    cout << endl;
    return 0;
}