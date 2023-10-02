#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char ch[100];
    cin.getline(ch, 100);
    int i=0, j=strlen(ch)-1;
    while(i<=j){
        swap(ch[i], ch[j]);
        i++; 
        j--;
    }
    cout<<"After reversing the string: ";
    cout<<ch<<endl;
}
