#include<iostream>
#include<vector>

using namespace std;

int numTree(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i -1; j++){
            dp[i] += dp[j] * dp[i -j -1];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int result = numTree(n);
    cout << result << endl;
}