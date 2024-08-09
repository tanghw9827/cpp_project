#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dailyTemperatures(const vector<int>& temp, vector<int>& ans){
    stack<int> s;
    s.push(0);
    for(int i = 0; i < temp.size(); i++){
        if(s.empty() || temp[i] <= temp[s.top()]){
            s.push(i);
        }else{
            while(!s.empty() && temp[i] > temp[s.top()]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
}

int main(){
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans(temp.size(), 0);
    dailyTemperatures(temp, ans);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}