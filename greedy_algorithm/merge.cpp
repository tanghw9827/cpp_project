#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
};

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if (n == 0) return {};  // 处理空输入

    sort(intervals.begin(), intervals.end(), cmp());  // 按左边界排序

    vector<vector<int>> result;  // 存储合并后的区间
    result.push_back(intervals[0]);  // 初始化result为第一个区间

    for (int i = 1; i < n; i++) {
        // 获取result中最后一个区间的引用
        vector<int>& lastInterval = result.back();

        if (intervals[i][0] <= lastInterval[1]) {
            // 当前区间与最后一个区间重叠，合并它们
            lastInterval[1] = max(lastInterval[1], intervals[i][1]);
        } else {
            // 当前区间不重叠，直接加入result
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {   
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals); 

    // 打印合并后的区间
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
