#include <iostream>

class Node {
	public:
    int data;
    Node* next;
};

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 11; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }
    printList(head);
    std::cout<<std::endl;

    Node* middleNode = findMiddle(head);
    std::cout << "Middle Node: " << middleNode->data << std::endl;

    return 0;
}