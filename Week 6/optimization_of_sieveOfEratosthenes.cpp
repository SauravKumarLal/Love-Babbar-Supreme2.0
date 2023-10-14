#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<bool> Sieve(int n){
    vector<bool> sieve(n+1, true);
    sieve[0]=sieve[1]=false;

    for(int i=2; i<=sqrt(n); i++){ //optimization 2: or i*i=n
        if(sieve[i] == true){

            int j=i*i; //optimization 1: first unmarked no. would be i*i, as others have been marked by 2 to i
            while(j<=n){
                sieve[j]=false;
                j+=i;
            }
        }
    }
    return sieve;
}

int main(){
    vector<bool> sieve = Sieve(25);
    for(int i=0; i<=25; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}