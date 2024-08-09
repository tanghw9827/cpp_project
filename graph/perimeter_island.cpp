#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                for(int k = 0; k < 4; k++){
                    int x = i + directions[k][0];
                    int y = j + directions[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0){
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}