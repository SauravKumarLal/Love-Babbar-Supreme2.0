#include<iostream>
#include<queue>

using namespace std;

int main(){
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty()){
            char frontChar = q.front();
            // this is not the ans
            if(freq[frontChar - 'a'] > 1){
                q.pop();
            }
            else{
                //==1 wala case, yahi ans hai
                cout<<frontChar<< "->";
                break;
            }
        }
        if(q.empty()){
            cout<<"#"<<"->";  
        }
    }
    return 0;
}