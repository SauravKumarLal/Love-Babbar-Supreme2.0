//TC of all except print() is O(1). //print() --> O(N).

#include<iostream>
#include<queue>

using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty!"<<endl;
        }
        else if(front == rear){
            arr[rear] = -1; 
            front == -1;
            rear == -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void push(int val){
        if(rear == size-1){
            cout<<"Queue overflows"<<endl;
            return;
        }
        else if(front == -1 && rear == -1){ //empty condition
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    int getSize(){
        if(front == -1 && rear == -1) return 0;
        return rear-front+1;
    }

    int getFront(){
        if(front == -1){
            cout<<"No element in queue, so no front element"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear == -1){
            cout<<"No element in queue, so no rear element"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print(){
        cout<<"Printing Queue: "<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<"-> ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    cout<<"The size of queue is: "<<q.getSize()<<endl;
    q.pop(); q.print();
    cout<<"The size of queue is: "<<q.getSize()<<endl;
    cout<<"The front element is: "<<q.getFront()<<endl;
    cout<<"The rear element is: "<<q.getRear()<<endl;
    
    return 0;
}