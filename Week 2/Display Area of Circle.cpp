#include<iostream>
#include<cmath>
using namespace std;

float area(float radius){
    cout<<"Area is: ";
    return 3.14*radius*radius;
}

int main(){
    int r;
    cin>>r;
    cout<<area(r);
}
