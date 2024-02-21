#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation 
    queue<int> q;

    //insertion
    q.push(5);

    //size
    cout<<"Size of queue: "<<q.size()<<endl;

    if(q.empty() == true){
        cout<<"Queue is empty!"<<endl;
    }
    else{
        cout<<"Queue is not empty!"<<endl;
    }

    //remove 
    q.pop();
    //sizeṇ
    cout<<"Size of queue: "<<q.size()<<endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Front element of queue is: "<<q.front()<<endl;
    cout<<"Last element of queue is: "<<q.back()<<endl; //also called as rear element

}