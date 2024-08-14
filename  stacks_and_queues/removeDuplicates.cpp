class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty() || s[i] != st.top()){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        string result(st.size(), 0);
        for(int i = st.size() -1; i >=0; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};