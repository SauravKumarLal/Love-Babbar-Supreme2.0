class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){ //not equals means part found in the string
            s.erase(s.find(part) ,part.length());
        }
        return s;
    }
};