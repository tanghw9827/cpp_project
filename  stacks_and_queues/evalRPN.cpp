class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string& token : tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                st.push(stoll(token));
            }else if(token == "+"){
                long long result1 = st.top();
                st.pop();
                long long result2 = st.top();
                st.pop();
                st.push(result2 + result1);
            }else if(token == "-"){
                long long result1 = st.top();
                st.pop();
                long long result2 = st.top();
                st.pop();
                st.push(result2 - result1);
            }else if(token == "*"){
                long long result1 = st.top();
                st.pop();
                long long result2 = st.top();
                st.pop();
                st.push(result2 * result1);
            }else if(token == "/"){
                long long result1 = st.top();
                st.pop();
                long long result2 = st.top();
                st.pop();
                st.push(result2 / result1);
            }
        }
        return st.top();
    }
};