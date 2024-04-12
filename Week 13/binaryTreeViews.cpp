#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* CreateTree(){
    cout<<"Enter the value of node: ";
    int value;
    cin>>value;

    if(value == -1){
        return NULL;
    }

    //create node
    Node* root = new Node(value);

    cout<<"Entering in left of "<<value<<endl;
    root->left = CreateTree();

    cout<<"Entering in right of "<<value<<endl;
    root->right = CreateTree();

    return root;
}

void preOrder(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(Node* root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void leftView(Node* root){ //using level order traversal
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 0)
                cout<<temp->data<<" ";
    
            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void rightView(Node* root){ //using level order traversal
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == n-1)
                cout<<temp->data<<" ";
    
            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}


void printLeftView(Node* root, int level, vector<int>& leftView){ //using recurssion
    if(root == NULL)
        return;
    if(level == leftView.size()){
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView){ //using recurssion
    if(root == NULL)
        return;
    if(level == rightView.size()){
        rightView.push_back(root->data);
    }
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}

void printTopView(Node* root){
    map<int, int> hdToNodeMap;
    queue<pair<Node*, int>> q; //pair bcuz <Node, horizontal distance OR Level>
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; //if iss horizontal distance k lie avi tak koi ans nhi aaya hai toh isko store krlo

        // if there is no entry for hd in map, then create a new entry
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode->data;
        }

        // child ko dekhna hai
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:hdToNodeMap)
        cout<<i.second<<" "; 
}

void printBottomView(Node* root){
    map<int, int> hdToNodeMap;
    queue<pair<Node*, int>> q; //pair bcuz <Node, horizontal distance OR Level>
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; //if iss horizontal distance k lie avi tak koi ans nhi aaya hai toh isko store krlo

        hdToNodeMap[hd] = frontNode->data;

        // child ko dekhna hai
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:hdToNodeMap)
        cout<<i.second<<" "; 
}

void printLeftBoundary(Node* root){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) return; //leaf node

    cout<<root->data<<" ";  
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);

}

void printRightBoundary(Node* root){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) return; //leaf node

    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";  
}

void boundaryTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
    printRightBoundary(root->right);
}

int main(){
    Node* root = CreateTree();
    levelOrderTraversal(root);
    // cout<<"Left view of the tree is: ";
    // leftView(root);
    // cout<<"Right view of the tree is: ";
    // rightView(root);
    // cout<<endl<<endl;

    // vector<int>leftView;
    // printLeftView(root, 0, leftView);
    // cout<<"Left view of the tree is: ";
    // for(int i=0; i<leftView.size(); i++){
    //     cout<<leftView[i]<<" ";
    // }
    // cout<<endl;

    // vector<int>rightView;
    // printRightView(root, 0, rightView);
    // cout<<"Right view of the tree is: ";
    // for(int i=0; i<rightView.size(); i++){
    //     cout<<rightView[i]<<" ";
    // }

    cout<<"Top view of the tree is: ";
    printTopView(root);
    cout<<endl;

    cout<<"Bottom view of the tree is: ";
    printBottomView(root);
    cout<<endl;

    cout<<"The boundary traversal value of the tree is: ";
    boundaryTraversal(root);
    
    
    return 0;
}
//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

//LECTURE 3 complete