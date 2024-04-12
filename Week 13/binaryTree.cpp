#include<iostream>
#include<queue>
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

void preOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    //N L R
    //N
    cout<<root->data<<" ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    //L N R
    //L
    inOrderTraversal(root->left);
    //N
    cout<<root->data<<" ";
    //R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    //L R N 
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout<<root->data<<" ";
}

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
    cout<<"The left of node \n"<<root->data<<", ";
    root->left = createTree();

    cout<<"The right of node \n"<<root->data<<", ";
    //step 2: create left subtree
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //start traversal
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            //valid node
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}

int main(){
    Node* root = createTree();
    // cout<<root->data<<endl;
    cout<<"\nPreorder of the tree is: ";
    preOrderTraversal(root);
    cout<<endl;
    
    cout<<"\nIneorder of the tree is: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"\nPostorder of the tree is: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"\nLevelorder of the tree is: ";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}

//10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1

