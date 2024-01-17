//METHOD1 - 2 part mei array ko devide kar ke, but usme memory wastage hoga 
//METHOD2 - 2 pointers ka use kar ke efficiently (as below)

#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data){
        if(top2-top1 == 1){
            cout<<"OVERFLOW!!"<<endl;
        } //as no space available
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"OVERFLOW!!"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout<<"UNDERFLOW!!"<<endl;
        }//stack 1 is empty
        else{
            arr[top1] = 0;
            top1--;
        }
    }
    
    void pop2(){
        if(top2 == size){
            cout<<"UNDERFLOW"<<endl;
        }//stack2 is empty
        else{
            arr[top2] = 0;
            top2++;
        }
    }
    void print(){
        cout<<endl;
        cout<<"top1: "<<top1<<endl;
        cout<<"top2: "<<top2<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Stack st(6);
    st.print();

    st.push1(10);
    st.print();

    st.push1(20);
    st.print();

    st.push2(100);
    st.print();

    st.push2(200);
    st.print();

    st.push2(300);
    st.print();

    st.push2(400);
    st.print();

    st.push1(1000); //OVERFLOW

    st.pop1();st.print();
    st.pop2();st.print();
    st.pop1();st.print();
    st.pop1(); //UNDERFLOW

    return 0;
}