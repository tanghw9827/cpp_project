#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int sum = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
            sum += nums[i][j];
        }
    }

    vector<int> nh(n, 0);
    vector<int> nv(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nh[i] += nums[i][j];
            nv[j] += nums[i][j];
        }
    }

    int result = INT_MAX;
    int h = 0;
    for (int i = 0; i < n; i++)
    {
        h += nh[i];
        result = min(result, abs(sum - h - h));
    }

    int v = 0;
    for (int i = 0; i < m; i++)
    {
        v += nv[i];
        result = min(result, abs(sum - v - v));
    }

    cout << result << endl;

    return 0;
}
