#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> hashTable(26,0);
    for(int i = 0; i < s.size(); i++){
        hashTable[s[i] - 'a'] = i;
    }
    vector<int> result;
    int left = 0, right = 0;
    for(int i = 0; i < s.size(); i++){
        right = max(right, hashTable[s[i] - 'a']);
        if(i == right){
            result.push_back(right - left + 1);
            left = i + 1;
        }
    }
    return result;
}

int main() {
    string s = "ababcbacadefegdehijhklij"; 
    vector<int> result = partitionLabels(s);
    for(auto r : result){
        cout << r << " ";
    }
    return 0;
}