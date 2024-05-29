#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    //it's not the first node
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){ //by referance, taaki pure tree ka track rakh sake, kuch v loss nhi hone chahiye
    cout<<"Enter data: ";
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data); //new node bana ke attach kr rhe purane nose se, that's why root = ''
        cout<<"Enter data:   ";
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){ //INORDER of a BST is always sorted
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* minValue(Node* root){
    if(root == NULL){
        cout<<"No Minimum value";
        return NULL;
    } 
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

int maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}


bool searchInBST(Node* root, int target){
    //base case
    if(root == NULL)
        return false;
    
    if(target == root->data) 
        return true;

    bool leftAns = false;
    bool rightAns = false;
    if(target < root->data){
        leftAns = searchInBST(root->left, target);
    }
    else{
        rightAns = searchInBST(root->right, target);
    }
    return leftAns || rightAns;
}

//4 different cases while deleting:
//1. Leaf node: both right & left -> NULL
//2. Node with left NULL & right non-NULL, 
//3. Node with right NULL & left non-NULL, 
//4. both left & right -> non-NULL, 2 options in this case ****
//   --> either choose max from left subtree or min from right subtree

Node* deleteFromBST(Node* root, int target){
    //target ko dhundo
    //target ko delete karo
    if(root == NULL)
        return NULL;
    
    if(root->data == target){
        //target mil gya, now delete --> 4 cases
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        else if(root->right == NULL && root->left != NULL){
            Node* childSubtree = root->left; 
            delete root;
            return childSubtree;
        }

        else if(root->right != NULL && root->left == NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        //**** CASE 4
        else{
            //right subtree ka max
            Node* mini = minValue(root->right);
            //replcement
            root->data = mini->data;
            
            //delete actual mini wali node
            root->right = deleteFromBST(root->right, mini->data);
            return root;
        }
    }
    else if(root->data > target){
        root->left = deleteFromBST(root->left, target); //recurssion se updated tree jo aaya usko root ke left mei lgaya
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, target);
        return root;
    }
    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"Preorder traversal is: ";
    preOrder(root);
    cout<<endl<<"Inorder traversal is: ";
    inOrder(root);
    cout<<endl<<"Postorder traversal is: ";
    postOrder(root);
    cout<<endl;

    //MIN element
    Node* minEle = minValue(root);
    if(minEle == NULL)
        cout<<"No element in tree, so no minimum value"<<endl;
    else
        cout<<"Minimum value of the tree is: "<<minEle->data<<endl;
    
    //MAX element
    cout<<"Maximum value of the tree is: "<<maxValue(root)<<endl;

    //SEARCH any number of element
    // int target;
    // cout<<"Enter the value of target: ";
    // cin>>target;
    // while(target != -1){
    //     bool search = searchInBST(root, target);
    //     if(search == true){
    //         cout<<"Present"<<endl;
    //     }
    //     else{
    //         cout<<"Not Present"<<endl;
    //     }
    //     cout<<"Enter the value of target: ";
    //     cin>>target;
    // }

    //DELETE
    int target;
    cout<<"Enter the value of target to delete: ";
    cin>>target;
    while(target != -1){
        root = deleteFromBST(root, target);
        cout<<"Level order traversal after deletion: "<<endl;
        levelOrderTraversal(root);
        cout<<"Enter the value of target: ";
        cin>>target;
    }

    return 0;
}

// BST Class 1 done.. start with class 2
// 50 30 60 25 40 70 80 -1