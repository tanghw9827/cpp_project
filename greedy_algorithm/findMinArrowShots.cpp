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

int findMinArrowShots(vector<vector<int>> &points)
{
    int n = points.size();
    int result = 1;
    if(n == 1) return 1;
    sort(points.begin(), points.end(), cmp());
    for(int i = 1; i < n; i++){
        if(points[i][0] > points[i-1][1]){
            result ++;
        }else{
            points[i][1] = min(points[i][1], points[i-1][1]);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    int result = findMinArrowShots(points);
    cout << result << endl;
    return 0;
}