#include<iostream>
#include<vector>

using namespace std;

int backpack(int m, int n, vector<int>& weights, vector<int>& values){
    vector<vector<int>> dp(m, vector<int>(n+1,0));
    for(int j = weights[0]; j <= n; j++){
        dp[0][j] = values[0];
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(j < weights[i]){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i]] + values[i]);
            }
        }
    }
    return dp[m-1][n];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> weights(m, 0);
    vector<int> values(m, 0);
    for(int i = 0; i < m; i++){
        cin >> weights[i];
    }
    for(int i = 0; i < m; i++){
        cin >> values[i];
    }
    int result = backpack(m, n, weights, values);
    cout << result << endl;
    return 0;
}