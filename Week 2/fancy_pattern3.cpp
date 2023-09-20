/*
*
*1*
*121*
*12321*
*121*
*1*
*
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int cond = i <= n/2 ? 2*i : 2*(n-i-1);     //condition variable
        for(int j=0; j<=cond; j++){
            if(j == 0 || j == cond){
                cout<<"*";
            }
            else if(j<=cond/2){
                cout<<j;
            }
            else{
                cout<<cond-j;
            }
        }
        cout<<endl;
    }
}