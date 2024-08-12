#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), cmp()); 
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < intervals[i - 1][1])
        {
            result++;
            intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
        }
    }
    return result;
}

int main()
{   
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    int result = eraseOverlapIntervals(intervals); 
    cout << result << endl;
    return 0;
}