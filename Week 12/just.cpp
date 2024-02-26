#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseFirstK(queue<int>& q, int k){
    stack<int> st;
    int n = q.size();

    for(int i = 0; i < k; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

    for(int i = 0; i < (n - k); i++){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main(){
    queue<int> q;
    q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);  q.push(60);
    reverseFirstK(q, 4);

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout << ele << " ";
    }

    return 0;
}
