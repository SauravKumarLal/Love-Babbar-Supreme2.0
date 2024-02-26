#include<iostream>
#include<queue>

using namespace std;

void interleaveQueue(queue<int>& q){
    int n = q.size();
    queue<int> q2;
    for(int i=0; i<n/2; i++){
        int temp = q.front();
        q2.push(temp);
        q.pop();
    }

    while(!q2.empty()){
        int temp1 = q.front();
        q.push(temp1);
        q.pop();

        int temp2 = q2.front();
        q.push(temp2);
        q2.pop();
    }
}


int main(){
    queue<int> q;
    q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);  q.push(60); q.push(70);  q.push(80);
    interleaveQueue(q);

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout<<ele<<" ";
    }
    
    return 0;
}