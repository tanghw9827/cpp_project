#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size(), -1); 
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            if (s.empty() || nums2[i] <= nums2[s.top()]) {
                s.push(i);
            } else {
                while (!s.empty() && nums2[i] > nums2[s.top()]) {
                    ans[s.top()] = nums2[i]; 
                    s.pop();
                }
                s.push(i);
            }
        }
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); i++) {
            m[nums2[i]] = ans[i];
        }
        
        vector<int> result(nums1.size(), 0); 
        for (int i = 0; i < nums1.size(); i++){
            result[i] = m[nums1[i]]; 
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
