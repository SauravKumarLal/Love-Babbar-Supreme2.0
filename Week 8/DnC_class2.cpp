#include<iostream>
using namespace std;

void printPermutation(string &str, int index){ //by referance m ans galt aarha, kyuki swap mei original string hi change hogyi
    //base case
    if(index >= str.length()){
        cout<<str<<" ";
        return;
    }

    for(int j=index; j<str.length(); j++){
        swap(str[index], str[j]);
        printPermutation(str, index+1);

        //backtracking, recursion se jo garbar hua by referance mei usko nullify kr diaa
        swap(str[index], str[j]);
    }
}

int main(){
    string str = "abc";
    int index = 0;
    printPermutation(str, index);
    return 0;
}