#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string result;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maxReach = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            result = "false";
            break;
        }
        maxReach = max(maxReach, i + v[i]);
        if (maxReach >= n - 1) {
            result = "true";
            break;
        }
    }
    cout << result << endl;
    return 0;
}