#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    bool ok = linearSearch(arr, 5, 10);
    if(ok == true){
        cout<<"Eelment Found!";
    }
    else
        cout<<"Eelment NOT Found!";

}