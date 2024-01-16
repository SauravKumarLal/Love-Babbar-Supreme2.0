#include<iostream>
#include<stack>
using namespace std;

void insertAtBottomOfStack(stack<int>& st, int& ele){  //by referance so that the changes will sustain throughout the code
    //Base Case
    if(st.empty()){
        st.push(ele);
        return;
    }

    //1 case hum solve karenge
    int temp = st.top();
    st.pop();

    //baaki recurssion dekhega 
    insertAtBottomOfStack(st, ele);

    st.push(temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    int ele = 400;

    insertAtBottomOfStack(st, ele);

    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}