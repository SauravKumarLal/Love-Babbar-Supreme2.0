//Replace @ with blank space

#include<iostream>
using namespace std;

void replaceSpecialChar(char ch[], int n){
    int i=0;
    while(ch[i] != '\0'){
        if(ch[i] == '@'){
            ch[i] = ' ';
        }
        i++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch, 20);
    replaceSpecialChar(ch, 20);
    cout<<ch<<endl;
    return 0;
}