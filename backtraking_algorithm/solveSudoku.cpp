class Solution {
public:
    bool isValid(int row, int col, const char& k, const vector<vector<char>>& board){
        //1.行是否重复
        for(int i=0;i<board[0].size();i++){
            if(board[row][i] == k) return false;
        }
        //2.列是否重复
        for(int i=0;i<board.size();i++){
            if(board[i][col] == k) return false;
        }
        //3.九宫格内是否重复
        for(int i=(row / 3) * 3;i<(row/3)*3+3;i++){
            for(int j=(col/3)*3;j<(col/3)*3+3;j++)
            if(board[i][j] == k) return false;
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.') continue;
                for(char k='1';k<='9';k++){
                    if(isValid(i,j,k,board)){
                        board[i][j]=k;
                        if(backtracking(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};