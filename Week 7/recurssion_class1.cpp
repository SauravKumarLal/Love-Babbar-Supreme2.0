#include<iostream>
#include<math.h>
using namespace std;

// FACTORIAL 

int factorial(int n){
    //base case
    if(n==1 || n==0){
        return 1;
    } 
    //processing -> can be above or below recurrive call

    //Recurrive Call
    int recussionKaAns = factorial(n-1);

    //processing -> can be above or below recurrive call
    int ans = n*recussionKaAns;
    return ans;
}

//REVERSE order counting print
void reverseCounting(int n){
    //base case
    if(n==1){
        cout<<"1"<<" ";
        return;
    }
    //processing ----> TAIL RECURSSION
    cout<<n<<" ";
    
    //Recurssive call
    reverseCounting(n-1);

    //processing ----> HEAD RECURSSION
    cout<<n<<" ";
}

//POWER of n
int power(int n){
    //Base case
    if(n==0){
        return 1; 
    }
    int ans = 2*power(n-1);
    return ans;
}

//FIBONACCI series
int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
    // int ans= fibonacci(n-1)+fibonacci(n-2);
    // return ans;    
}

//SUM
int sum(int n){
    if(n==1) return 1;
    int ans = n + sum(n-1);
    return ans;
}

int main(){
    // cout<<factorial(n);
    // reverseCounting(5);
    // cout<<power(6);
    // cout<<fibonacci(9);
    cout<<sum(10);
    return 0;
}