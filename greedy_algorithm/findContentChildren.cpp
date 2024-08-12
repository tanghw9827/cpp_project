#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s){
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index = 0;
    for(int i = 0; i < s.size(); i++){
        if(index < g.size() && s[i] >= g[index]){
            index++;
        }
    }
    return index;
}

int main() {
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    int result = findContentChildren(g, s);
    cout << result << endl;
    return 0;
}