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

void sortStack(stack<int> &st){
    //Base Case
    if(st.empty()){
        return;
    }

    //1 case hum solve karenge
    int temp = st.top();
    st.pop();

    //recurssion
    sortStack(st);

    insertInSortedStack(st, temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(40);
    st.push(20);
    st.push(80);
    st.push(30);

    sortStack(st);

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}