#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(const int& a, const int& b) {
        return abs(a) > abs(b);
    }
};

int largestSumAfterKNegations(vector<int>& nums, int k) {
    // 按照绝对值从大到小排序
    sort(nums.begin(), nums.end(), cmp());

    // 逐个将负数取反
    for (int i = 0; i < nums.size(); ++i) {
        if (k > 0 && nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    // 如果还有剩余的取反次数且为奇数，取反绝对值最小的元素
    if (k % 2 == 1) {
        nums[nums.size() - 1] = -nums[nums.size() - 1];
    }

    // 计算数组的总和
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    vector<int> nums = {4, 2, 3};
    int k = 1;
    int result = largestSumAfterKNegations(nums, k);
    cout << result << endl;
    return 0;
}
