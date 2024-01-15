//we can always use stack to reverse something

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "SauravTuPhodega!";
    stack<char> st;
    int x = str.length();
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        st.push(ch);
    }

    while( !st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}