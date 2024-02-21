#include<iostream>
#include<queue>

using namespace std;

class CQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;
        CQueue(int size){
            arr = new int[size]; 
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int x){
            //overflow
            if((front == 0 && rear == size-1) || rear == front-1){ //common mistake that ppl do 
                cout<<"Queue overflow!"<<endl;
            }
            //empty case
            else if(front==-1 && rear==-1){ //log add krna hi bhul jaate hain ye case   
                front++; rear++;
                arr[rear] = x;
            }
            //circular queue
            else if(rear == size-1 && front != 0){
                rear=0;
                arr[rear] = x;
            }
            //normal case
            else{
                rear++;
                arr[rear] = x;
            }
        }

        void pop(){
            //underflow
            if(front == -1 && rear == -1){
                cout<<"Queue underflow!"<<endl;
            }
            //1 element
            else if(front==rear){
                arr[front] == -1;
                // front++;
                front = -1; rear = -1;
            }
            //circular queue
            else if(front == size-1){
                arr[front] = -1;
                front = 0;
            }
            //normal queue
            else{
                arr[front] = -1;
                front++;
            }
        }
        void print(){
            cout<<"Printing Queue: ";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<"-> ";
            }
            cout<<endl;
        }
};

int main(){
    CQueue q(5);
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
    
    q.push(60);
    // q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();
    q.push(110);
    q.print();
    q.push(120);
    q.print();
    q.push(130);
    q.print();

}