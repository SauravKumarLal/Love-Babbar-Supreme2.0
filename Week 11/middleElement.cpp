#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    int x = st.size();
    if(x%2 == 0){
        x=x/2;
    }else{
        x= (x/2)+1;
    }
    for(int i=0; i<x-1; i++){
        st.pop();
    }
    cout<<"Middle Element is: "<<st.top()<<endl;
}