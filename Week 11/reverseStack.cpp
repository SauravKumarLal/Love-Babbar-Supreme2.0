#include<iostream>
#include<stack>
using namespace std;

void insertAtBottomOfStack(stack<int>& st, int& ele){  
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

void reverseStack(stack<int> &st){
    //Base Case
    if(st.empty()){
        return;
    }

    //1 case hum solve karenge
    int temp = st.top();
    st.pop();

    //recurssion
    reverseStack(st);

    insertAtBottomOfStack(st, temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    cout<<st.top()<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}


//can be done by using inserAtBottom function