//LEETCODE-242

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> map1;
        for(auto x: s){
            map1[x]++;
        }
        unordered_map <char, int> map2;
        for(auto x: t){
            map2[x]++;
        }
        return map1 == map2; 
    }
};

//approch 2 - sort and compare