#include<iostream>
using namespace std;

void printPrime(int n){
    for(int i=2; i<=n; i++){
        int count=0;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                count++;
            }
        }
        if(count==0){
            cout<<i<<" ";     
        }
    }
}
// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47.

int main(){
    int n;
    cin>>n;
    printPrime(n);
    return 0;
}
