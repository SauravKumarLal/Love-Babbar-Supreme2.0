#include<iostream>
using namespace std;

void reverseString(string &s, int start, int end){
    //Base Case
    if(start>end) return;
    swap(s[start], s[end]);
    reverseString(s, start+1, end-1);
}

int main(){
    string s;
    cin>>s;
    int start = 0;
    int end = s.size()-1;
    reverseString(s, start, end);
    cout<<s<<endl;
    return 0;
}