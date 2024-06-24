//A prefix is given, print all the words which is starting from that prefix
#include<iostream>
#include<vector>
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

void findPrefixString(TrieNode* root, string input, vector<string>& ans){
    
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
    
    string input = 'c';
    vector<string> ans;

    findPrefixString(root, input, ans);

    for(auto i: ans){
        cout<<i<<endl;
    }
}