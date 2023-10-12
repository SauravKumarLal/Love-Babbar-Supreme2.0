#include<iostream>

using namespace std;

int fastExponentiation(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1){ //if it's odd.......... for even (!(b&1))
            ans *= a;
        }
        a *= a;
        b>>=1;  //right shift by 1 i.e. b=b/2
    }
    return ans;
} //T.C. = O(log(b))

int slowExponentiation(int a, int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans *= a;
    }
    return ans;
} //T.C. = O(b)
 
int main(){
    cout<<fastExponentiation(5, 3);
    return 0;
}