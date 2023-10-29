#include<iostream>
using namespace std;

int x=2; //global variable

void fun(){
    ::x = 6;
    int x=100;
    cout<<x<<endl; //most local have more preference 
    cout<<::x<<endl; //accessing global variable using ::
}

int main(){
    ::x = 4; //global x
    int x = 20; //local to main() fn.
    cout<<x<<endl;
    cout<<::x<<endl; //accessing global variable using ::
    {
        int x=10;
        {
            int x=98;
            cout<<x<<endl;
        }
        cout<<x<<endl; //most local have more preference 
        cout<<::x<<endl; //accessing global variable using ::
    }
    fun();
    return 0;
}