#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void rightHanded(string& s, int k){
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+k);
    reverse(s.begin()+k, s.end());
}

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    rightHanded(s, k);
    cout << s << endl;
    return 0;
}