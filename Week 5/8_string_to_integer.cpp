//LEETCODE - 8


// class Solution {
// public:
//     int myAtoi(string s) {
//         int x = atoi(s.c_str()); //c.str() -> changes a string to character array with null character at the end
//         return x;
//     }
// };


class Solution {
public:
    int myAtoi(string s) {
        int ans=0, i=0, sign = 1; //+ve sign
        while(s[i] == ' '){
            i++;
        }

        while(i<s.length() && (s[i] == '+' || s[i] == '-')){
            if((s[i] == '+' || s[i] == '-') && (s[i+1] == '+' || s[i+1] == '-'))
                return 0;
            sign = s[i] == '+' ? 1 : -1;
            ++i;
        }

        
        while(i<s.length() && isdigit(s[i])){
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && s[i] > '7')){
                return sign == -1?INT_MIN:INT_MAX;
            }
            ans = ans*10 + (s[i] - '0');
            ++i;
        }
        return ans*sign;
    }
};