#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size();
    vector<int> profit(n, 0);
    for(int i = 0; i < n-1; i++){
        profit[i+1] = prices[i+1] - prices[i];
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        if(profit[i] > 0){
            result += profit[i];
        }
    }
    return result;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int result = maxProfit(prices);
    cout << result << endl;
    return 0;
}