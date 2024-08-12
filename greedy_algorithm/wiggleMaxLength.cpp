#include <iostream>
#include <vector>
#include <string>
using namespace std;

int wiggleMaxLength(vector<int>& nums){
    int n = nums.size();
    if(n <= 1) return n;
    int result = 1;
    int prediff = 0;
    int curdiff;
    for(int i = 0; i < n - 1; i++){
        curdiff = nums[i+1] - nums[i];
        if((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)){
            result++;
            prediff = curdiff;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int result = wiggleMaxLength(nums);
    cout << result << endl;
    return 0;
}