#include <iostream>
#include <vector>
#include <string>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> nums(n, 1);
    for(int i = 1; i < n; i++){
        if(ratings[i] > ratings[i-1]){
            nums[i] = nums[i-1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(ratings[i] > ratings[i+1]){
            nums[i] = max(nums[i], nums[i+1] + 1);
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    return sum;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    int result = candy(ratings);
    cout << result << endl;
    return 0;
}