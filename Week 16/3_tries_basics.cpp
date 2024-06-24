#include<iostream>
using namespace std;

class TrieNode{
    public:
    int value;
    TrieNode* children[26];
    bool isTerminal = false;

    TrieNode(int val){
        this->value = val;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

//insertion
void insertWord(TrieNode* root, string word){
    // cout<<"received word: "<<word<<" for insertion."<<endl;
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }
    else{
        //absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    //recurssion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        return root->isTerminal;
    }
    //1 case mera
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }
    else{
        //absent
        return false;
    }
    //baaki recurssion
    bool recKaAns = searchWord(child, word.substr(1));
    return recKaAns;

}

void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }
    //1 case mera
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }
    else{
        //absent
        return;
    }
    //baaki recurssion tera
    deleteWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    
    cout<<"Insertion Done!"<<endl;

    if(searchWord(root, "lover")){
        cout<<"Found!"<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }

    deleteWord(root, "lover");
    
    if(searchWord(root, "lover")){
        cout<<"Found!"<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}