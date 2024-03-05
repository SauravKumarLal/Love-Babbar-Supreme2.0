#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

//first left subtree banke ready hoga, then right subtree will form
Node* createTree(){
    cout<<"Enter the value of data: ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    //step 1: create Node
    Node* root = new Node(data);

    //step 2: create left subtree
    cout<<"The left of node "<<root->data<<", ";
    root->left = createTree();

    cout<<"The right of node "<<root->data<<", ";
    //step 2: create left subtree
    root->right = createTree();

    return root;
}

int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    return 0;
}