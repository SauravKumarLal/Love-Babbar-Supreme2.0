// LEETCODE - 917

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0, j=s.length()-1;
        while(i<=j){
            if((s[i]<=64) || (s[i]>=91 && s[i]<=96) || s[i]>= 123){
                i++;
            }
            
            else if((s[j]<=64) || (s[j]>=91 && s[j]<=96) || s[j]>= 123){
                j--;
            }

            else{
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};

// class Solution {
// public:
//     string reverseOnlyLetters(string s) {
//         int i = 0, j = s.length() - 1;
//         while (i <= j) {
//             if (!isLetter(s[i])) {
//                 i++;
//             } else if (!isLetter(s[j])) {
//                 j--;
//             } else {
//                 swap(s[i], s[j]);
//                 i++;
//                 j--;
//             }
//         }
//         return s;
//     }

// private:
//     bool isLetter(char c) {
//         return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
//     }
// };
