#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string letterMap[10] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz", // 9
};

void backtracking(const string &digits, int startIndex, string &path, vector<string> &result)
{
    if (startIndex == digits.size())
    {
        result.push_back(path);
        return;
    }
    int digit = digits[startIndex] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++)
    {
        path.push_back(letters[i]);
        backtracking(digits, startIndex + 1, path, result);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> result = {};
    if (digits.size() == 0)
    {
        return result;
    }
    string path;
    backtracking(digits, 0, path, result);
}

int main()
{
    //
    return 0;
}