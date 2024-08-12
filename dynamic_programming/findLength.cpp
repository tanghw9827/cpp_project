#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int result = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                dp[i][j] = 0;
            }
            if (dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    int result = findLength(nums1, nums2);
    cout << result << endl;
    return 0;
}