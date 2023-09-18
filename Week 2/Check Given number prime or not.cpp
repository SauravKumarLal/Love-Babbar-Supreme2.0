#include<iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
        else{
            return true;
        }
    }
}

int main(){
    int n;
    cin>>n;
    bool Prime = isPrime(n);
    if(Prime == false){
        cout<<"Not Prime No.";
    }
    else{
        cout<<"Prime No.";
    }

}
