/*
*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n/2; i++){
        // int cond = i <= n/2 ? i : n-i+1; 
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=n-2*i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }


    for(int i=n/2; i>0; i--){
        // int cond = i <= n/2 ? i : n-i+1; 
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=n-2*i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}