#include<iostream>
using namespace std;

int reverse(int n){
    int y =0;
    for(int i=0; i<=n; i++){
        int rem = n%10;
        y = 10*y+rem;
        n=n/10;
    }
    return y;
}

int main(){
    int n;
    cin>>n;
    cout<<reverse(n);
}
