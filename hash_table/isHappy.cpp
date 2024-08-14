class Solution {
public:
    int cal(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> uset;
        while (1) {
            if (n == 1) {
                return true;
            } else {
                n = cal(n);
                if (uset.find(n) != uset.end()) {
                    return false;
                } else {
                    uset.emplace(n);
                }
            }
        }
        return true;
    }
};