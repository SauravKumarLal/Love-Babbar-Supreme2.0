#include<iostream>
using namespace std;

void toUppercase(char ch[], int n){
    int i=0;
    while(ch[i] != '\0'){
        if(ch[i]>= 'a' && ch[i]<= 'z'){
            ch[i] += 'A'-'a';
        }
        i++;
    }
    // cout<<ch[i]<<endl;
    
}

int main(){
    char ch[100];
    cin.getline(ch, 100); 
    toUppercase(ch, 100);
    cout<<"Uppercase char is: "<<ch;
}