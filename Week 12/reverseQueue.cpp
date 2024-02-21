#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> st;

    while(!q.empty()){
        int frontEle = q.front();
        q.pop();

        st.push(frontEle);
    }

    //one by one queue se lo nd stack se push karo
    while(!st.empty()){
        int topEle = st.top();
        st.pop();

        q.push(topEle);
    }
}


int main(){
    queue<int> q;

    q.push(10); q.push(20); q.push(30); q.push(40); q.push(50); q.push(60); 

    reverseQueue(q);

    cout<<"Reverse of the queue is: "<<endl;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }
}