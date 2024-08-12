#include<iostream>
#include<vector>

using namespace std;

bool canPartition(vector<int>& stones){
    int sum = 0;
    for(int i = 0; i < stones.size(); i++){
        sum += stones[i];
    }
    int target = sum / 2;
    vector<int> dp(target+1, 0);
    for(int i = 0; i < stones.size(); i++){
        for(int j = target; j >= stones[i]; j--){
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - 2 * dp[target];
}

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    bool result = canPartition(stones);
    cout << result << endl;
    return 0;
}