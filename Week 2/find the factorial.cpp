#include<iostream>
using namespace std;

int factorial(int n){
    int p = 1;
    for(int i=n; i>0; i--){
        p = p*i;
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n);
}
