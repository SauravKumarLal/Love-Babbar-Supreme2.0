#include<iostream>
using namespace std;

int main(){
    char ch[10];
    // cin>>ch; --> works without spaces
    cin.getline(ch, 10); 
    cout<<"char is: "<<ch;
}