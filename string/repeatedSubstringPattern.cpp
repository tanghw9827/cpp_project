#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s){
    string s1 = s + s;
    s1.erase(s1.begin());
    s1.erase(s1.end()-1);
    if(s1.find(s) != string::npos){
        return true;
    }else{
        return false;
    }
}

int main() {
    string s;
    cin >> s;
    bool result = repeatedSubstringPattern(s);
    cout << result << endl;
    return 0;
}