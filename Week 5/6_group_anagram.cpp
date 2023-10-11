//LEETCODE - 49

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> umap;
        for(auto str: strs){
            string s = str;
            sort(s.begin(), s.end());
            umap[s].push_back(str);
        }
        vector<vector<string>> ans;

        for(auto it=umap.begin(); it != umap.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};

//method - 2 -- without sorting & using hash map
class Solution {
public:

    std::array<int, 256> hash(string s){
        std::array<int, 256> hash = {0};
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <std::array<int, 256>, vector<string>> umap;
        for(auto str: strs){
            umap[hash(str)].push_back(str);
        }
        vector<vector<string>> ans;

        for(auto it=umap.begin(); it != umap.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};