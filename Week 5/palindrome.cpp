#include<iostream>
#include<string.h>
using namespace std;

bool paindrome(char ch[]){
    int i=0, j=strlen(ch)-1;
    char ch1[100];
    // ch1 = ch;
    strcpy(ch1, ch);
    while(i<=j){
        swap(ch1[i], ch1[j]);
        i++; j--;
    }
    if(strcmp(ch, ch1) == 0)
        return true;
    else
        return false;
}

int main(){
    char ch[100];
    cin.getline(ch, 100);
    
    bool bl = paindrome(ch);
    if(bl == true){
        cout<<"Palindrome string!";
    }
    else{
        cout<<"Not a Palindrome string!";
    }
}