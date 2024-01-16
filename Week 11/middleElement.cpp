#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans){
    //base case
    if(pos == 1){
        ans = st.top();
        //ans = st.pop(); --> to delete the middle element
        // cout<<"Deleting: "<<st.top()<<endl;
        // st.pop();
        return;
    } 

    //1 case hum solve karenge
    pos--;
    int temp = st.top();
    st.pop();

    //recurssiom
    solve(st, pos, ans);

    //insert
    st.push(temp);
}

int getMiddleElement(stack<int> &st){
    int size = st.size();
    if(st.empty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else{
        //stack is not empty
        int pos=0;
        if(!(size & 1)){
            pos=size/2;
        }else{
            pos= (size/2)+1;
        }
        int ans = -1;
        solve(st, pos, ans);    
        return ans;
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    // cout<<"Before Size: "<<st.size()<<endl;
    int mid = getMiddleElement(st);
    cout<<"Middle Element is: "<<mid<<endl;
    // cout<<"After Size: "<<st.size()<<endl;
    // int x = st.size();
    // if(x%2 == 0){
    //     x=x/2;
    // }else{
    //     x= (x/2)+1;
    // }
    // for(int i=0; i<x-1; i++){
    //     int temp = st.top();
    //     temp.pop();
    // }
    // cout<<"Middle Element is: "<<st.top()<<endl;
}

//BUT Isme stack hi chota hogya!... talking about upper commented part in main function