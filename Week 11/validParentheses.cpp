// 20. Valid Parentheses
//jab v open bracket aayega toh push, else if closing bracket aaya and uska open bracket mila toh pop
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                //push for opening bracket
                st.push(ch);
            }
            else{
                //closing bracket -> match and pop
                if(!st.empty()){
                    if(ch == ')' && st.top() == '('){
                        st.pop();
                    }
                    else if(ch == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};