#include <iostream>
#include <vector>
#include <string>
using namespace std;

int change(int n, vector<int>& coins){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++){
        for(int j = coins[i]; j <= n; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[n];
}

int main() {
    int n = 5;
    vector<int> coins = {1,2,5};
    int result = change(n, coins);
    cout << result << endl;
    return 0;
}