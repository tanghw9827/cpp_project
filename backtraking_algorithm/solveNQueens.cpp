class Solution {
public:
    bool isValid(int row, int col, const int& n,
                 const vector<string>& chessboard) {
        // 1. 同一列进行检查
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        // 2. 45度方向进行检查
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        // 3. 135度方向进行检查
        for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtracking(const int& n, int row, vector<string>& chessboard,
                      vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, chessboard)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard, result);
                chessboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> chessboard(n, string(n,'.'));
        backtracking(n, 0, chessboard, result);
        return result;
    }
};