#include<iostream>
#include<vector>

using namespace std;

int backPack(int m, int n, vector<int>& weights, vector<int>& values){
    vector<int> dp(n+1,0);
    for(int i = 0; i < m; i++){
        for(int j = n; j >= weights[i]; j--){
            dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
        }
    }    
    return dp[n];
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
    int result = backPack(m, n, weights, values);
    cout << result << endl;
    return 0;
}