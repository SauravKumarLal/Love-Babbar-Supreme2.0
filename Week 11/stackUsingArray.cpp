#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr; //dynamic array
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size-1){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Stack underflow!"<<endl;
        }
        else{
            top--;
        }
    }

    // void isEmpty(){
    //     if(top == -1){
    //         cout<<"Stack is empty";
    //     }else{
    //         cout<<"Stack is non-empty";
    //     }
    // }

    bool isEmpty(){
        if(top == -1){
            return true;  
        } 
        else{
            return false;
        } 
    }

    int getTop(){
        if(top == -1){
            cout<<"Stack empty!"<<endl;
        }
        else{
            return arr[top];
        }
        return -1;
    }

    int getSize(){
        // return arr.size(); 
        return top+1; 
    }

    void print(){
        cout<<"Top: "<<top<<endl;
        cout<<"Top Element: "<<getTop()<<endl;

        cout<<"Stack: ";
        for(int i=0; i<getSize(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

int main(){
    //creation()
    Stack st(8);
    st.push(11);
    st.print();

    st.push(22);
    st.print();
    cout<<"Top element is: "<<st.getTop()<<endl;
    cout<<"Size is: "<<st.getSize()<<endl;
    if(st.isEmpty()){
        cout<<"Stack is empty!"<<endl;
    } 
    else{
        cout<<"Stack is non-empty!"<<endl;
    }

    st.push(33);
    st.print();
    
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();

    return 0;
}