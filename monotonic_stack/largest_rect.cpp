#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void rectCal(const vector<int>& height, int& result){
    stack<int> st;
    for(int i = 0; i < height.size(); i++){
        if(st.empty() || height[i] >= height[st.top()]){
            st.push(i);
        } else{
            while(!st.empty() && height[i] < height[st.top()]){
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = height[mid];
                    int w = i - st.top() - 1;
                    result = max(result, h * w);
                }
            }
            st.push(i);
        }
    }
}

int main(){
    vector<int> height = {2,1,5,6,2,3};
    height.insert(height.begin(), 0);
    height.push_back(0);
    int result = 0;
    rectCal(height, result);
    cout << result << endl;
    return 0;
}