#include<iostream>
using namespace std;

int main(){
    int a=5;
    cout<<a;
    cout<<"address of a: "<<&a<<endl;

    int* ptr = &a;
    cout<<"Accessing: "<<*ptr<<endl; //dereferencing -- jo v address ptr m store hai uss address m jo value hai
    cout<<&ptr<<endl;

}