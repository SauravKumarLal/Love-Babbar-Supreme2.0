#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=n; i>=1; i--){
        for(int j=i; j>=1; j--){
            if((i>2 && i<n) && (j>1 && j<i)){
                cout<<"  ";
            }
            else{
                cout<<n-j+1<<" ";
            }
        }
        cout<<endl;
    }
}
