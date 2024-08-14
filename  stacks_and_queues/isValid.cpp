class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(')');
            }else if(s[i] == '['){
                st.push(']');
            }else if(s[i] == '{'){
                st.push('}');
            }else if(st.empty() || s[i] != st.top()){
                return false;
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};