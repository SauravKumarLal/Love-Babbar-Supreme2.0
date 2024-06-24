//unordered map - O(1)
//ordered map - O(logn)
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string, int> mp;

    //creation
    pair<string, int> p = make_pair("love", 25);
    pair<string, int> q("saurav", 21);
    pair<string, int> r;
    r.first = "Sonu";
    r.second = 22;

    //insertion
    mp.insert(p);
    mp.insert(q);
    mp.insert(r);
    mp["lal"] = 20;

    cout<<"Size is: "<<mp.size()<<endl;

    //access
    cout<<mp.at("saurav")<<endl;
    cout<<mp["saurav"]<<endl;

    //searching
    cout<<mp.count("saurav")<<endl; //return either 0 or 1
    if(mp.find("lala") != mp.end()){
        cout<<"Found!"<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }

    cout<<"Size is: "<<mp.size()<<endl;
    cout<<mp["kumar"]<<endl;
    cout<<"Size is: "<<mp.size()<<endl; //if kumar available nhi hai n hum [] se access kr rhe hai toh wo new entry(kumar, 0) create kr deti hai
}