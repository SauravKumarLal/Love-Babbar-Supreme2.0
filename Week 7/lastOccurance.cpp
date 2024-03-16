//we can use STL fn. strrchr() for the same thing
//char *strrchr(const char *str, int chr);  --> Syntax

#include<iostream>
using namespace std;

// iterative method
int lastOccuranceOfCharItr(string s, char x, int i, int &ans){
    for(int i=0; i<s.length(); i++){
        if(x == s[i]){
            ans = i;
        }
    }
    return ans;
}

// recurssive method --> L to R
void lastOccuranceOfChar(string s, char x, int i, int &ans){
    //base case
    if(i>=s.size()) return;

    //ek case we'll solve
    if(s[i] == x){
        ans = i;
    }

    lastOccuranceOfChar(s, x, i+1, ans);
}

// recurssive method --> R to L
void lastOccuranceOfCharRtoL(string s, char x, int i, int &ans){
    //base case
    if(i<0) return;

    //ek case we'll solve
    if(s[i] == x){
        ans = i;
        return;
    }
    lastOccuranceOfCharRtoL(s, x, i-1, ans);
}

int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int ans=-1;
    // int i=0;
    int i = s.length()-1;

    lastOccuranceOfCharRtoL(s, x, i, ans);
    cout<<ans;
    return 0;
}