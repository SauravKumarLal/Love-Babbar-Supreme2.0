//LEETCODE - 205

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size()) {
            return false; 
        }

        int hash[256] = {0};
        bool isCharMapped[256] = {0};

        for(int i=0; i<s.size(); i++){
            if(hash[s[i]]==0 && isCharMapped[t[i]]==0){
                hash[s[i]] = t[i];
                isCharMapped[t[i]] = true;
            }
        }

        for(int i=0; i<s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};