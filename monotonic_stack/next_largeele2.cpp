#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // 初始化结果数组为-1
        stack<int> s;

        // 遍历两次数组，因为是循环数组
        for (int i = 0; i < 2 * n; i++) {
            int currentIndex = i % n; // 计算当前索引
            if (s.empty() || nums[currentIndex] <= nums[s.top()]) {
                if (i < n) { // 只在第一次遍历时压栈
                    s.push(currentIndex);
                }
            } else {
                while (!s.empty() && nums[currentIndex] > nums[s.top()]) {
                    ans[s.top()] = nums[currentIndex]; // 更新答案数组
                    s.pop();
                }
                if (i < n) { // 仍然需要将当前索引压栈
                    s.push(currentIndex);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElements(nums);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
