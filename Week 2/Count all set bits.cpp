#include<iostream>
using namespace std;

int countSetBits(int n){
    int count=0;
    while(n>=1){
        if(n%2 == 1){
            count++;
        }
        n = n/2;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<countSetBits(n);
}
