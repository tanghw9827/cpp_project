#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countSubstrings(string s)
{
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int result = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    { // 注意遍历顺序
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                { // 情况一 和 情况二
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                { // 情况三
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}

int main()
{
    string s = "aaa";
    int result = countSubstrings(s);
    cout << result << endl;
    return 0;
}
