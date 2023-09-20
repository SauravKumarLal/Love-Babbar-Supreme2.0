/*
1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1
*/

#include<iostream>
using namespace std;

int main(){
    int x=1;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=2*i-1; j++){
            if(j%2 != 0){
                cout<<x;
                x++;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }

    int y=7;  
    for(int i=4; i>=1; i--){  
        for(int j=1; j<=2*i-1; j++){
            if(j%2 != 0){
                cout<<y;
                y++;
            }
            else{
                cout<<"*";
            }
        }
        // int y = 
        cout<<endl;
    }
}