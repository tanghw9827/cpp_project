#include <iostream>
#include <vector>
#include <string>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for(int i = 0; i < gas.size(); i++){
        curSum += (gas[i] - cost[i]);
        totalSum += (gas[i] - cost[i]);
        if(curSum < 0){
            curSum = 0;
            start = i + 1;
        }
    }
    if(totalSum < 0) return -1;
    return start;
}

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = canCompleteCircuit(gas, cost);
    cout << result << endl;
    return 0;
}