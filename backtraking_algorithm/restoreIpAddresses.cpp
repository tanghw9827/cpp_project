#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string &s, int start, int end)
{
    if (s[start] == '0' && start != end)
    {
        return false;
    }
    int num = stoi(s.substr(start, end - start + 1));
    if (num > 255)
        return false;
    return true;
}

void backtracking(string &s, int startIndex, int &pointSum, string &path, vector<string> &result)
{
    if (pointSum == 3)
    {
        if (isValid(s, startIndex, s.size() - 1))
        {
            result.push_back(path + s.substr(startIndex)); 
        }
        return;
    }

    for (int i = startIndex; i < s.size(); i++)
    {
        if (isValid(s, startIndex, i))
        {
            path.push_back(s[i]); 
            path.push_back('.'); 
            pointSum++; 
            backtracking(s, i + 1, pointSum, path, result);
            pointSum--; 
            path.pop_back(); 
            path.pop_back(); 
        }
        else
        {
            break; 
        }
    }
}

int main() {
    cout << result << endl;
    return 0;
}