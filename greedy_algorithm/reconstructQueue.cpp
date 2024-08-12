#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] <= b[1];
        return a[0] > b[0];
    }
};

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp());
    vector<vector<int>> result;
    for(int i = 0; i < people.size(); i++){
        int position = people[i][1];
        result.insert(result.begin() + position, people[i]);
    }
    return result;
}

int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> result = reconstructQueue(people);
    for(int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}