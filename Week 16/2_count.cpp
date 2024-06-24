#include<iostream>
#include<unordered_map> 
#include<map> //ordered map gives output in sorted order
using namespace std;

int main(){
    string str = "sauravkumarlal";
    // unordered_map<char, int> mp; 
    map<char, int> mp;
    for(char i: str){ //int i=0; i<str.length(); i++
        mp[i]++;
    }
    for(auto i: mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
}