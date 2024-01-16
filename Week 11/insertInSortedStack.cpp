#include<iostream>
#include<stack>
using namespace std;

void insertInSortedStack(stack<int> &st, int &element){
    //Base Case
    if(st.empty() || st.top()<element){ //yaha pe galti kara maine, and sab karte hain!*****, so check if stack is empty
        st.push(element);
        return;
    }
    
    //1st step
    int temp = st.top();
    st.pop();

    //recurssion
    insertInSortedStack(st, element);

    st.push(temp);
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);

    int element = 2;
    insertInSortedStack(st, element);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}