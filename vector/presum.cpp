#include <iostream>
#include <vector>
#include <string>
using namespace std;

int preSum(vector<int>& vec, int a, int b){
    int sum = 0;
    vector<int> nums(vec.size(), 0);
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
        nums[i] = sum;
    }
    if(a == 0){
        return nums[b];
    } else{
        return nums[b] - nums[a-1];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int a, b;
    while (cin >> a >> b)
    {
        int sum = preSum(vec, a, b);
        cout << sum << endl;
    }
    return 0;
}