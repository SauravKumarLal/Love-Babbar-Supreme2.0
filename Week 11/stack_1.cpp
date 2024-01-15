#include<iostream>
#include<stack>

using namespace std;

int main(){
    //we can't access stack using index, there's only 1 way to stack that's using top();
    stack<int> st;
    st.push(10);
    st.push(11);
    st.push(12);

    cout<<"Size of stack is: "<<st.size()<<endl;
    st.pop();
    cout<<"Size of stack is: "<<st.size()<<endl;

    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is non-empty"<<endl;
    }
    cout<<st.top()<<endl;
    return 0;
}