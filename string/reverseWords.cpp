#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &s) {
    int i = 0, j = s.size() - 1;
    
    // 去除前导空格
    while (s[i] == ' ' && i <= s.size() - 1) {
        i++;
    }
    
    // 去除尾随空格
    while (s[j] == ' ' && j >= 0) {
        j--;
    }
    
    string result;
    
    // 处理单词之间的多余空格并生成去掉多余空格的字符串
    for (int k = i; k <= j; k++) {
        if (s[k] != ' ') {
            result.push_back(s[k]);
        } else if (!result.empty() && result.back() != ' ') {
            result.push_back(' ');
        }
    }
    
    // 替换原字符串
    s = move(result);
    
    // 整个字符串反转
    reverse(s.begin(), s.end());
    
    int m = 0;
    
    // 逐个单词反转回去
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            reverse(s.begin() + m, s.begin() + i);
            m = i + 1;
        }
    }
}

int main() {
    string s;
    // 使用 getline 读取整行输入
    getline(cin, s);
    
    reverseWords(s);
    
    cout << s << endl;
    return 0;
}
