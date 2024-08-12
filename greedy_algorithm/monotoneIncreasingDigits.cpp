#include <iostream>
#include <string>
using namespace std;

int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    int mark = s.size();  // 记录需要变成9的起始位置
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i - 1] > s[i]) {
            s[i - 1]--;
            mark = i;  // 记录从哪个位置开始变成9
        }
    }
    for (int i = mark; i < s.size(); i++) {
        s[i] = '9';
    }
    return stoi(s);
}

int main() {
    int N = 100;
    int result = monotoneIncreasingDigits(N);
    cout << result << endl;
    return 0;
}
