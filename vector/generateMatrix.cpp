class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startx = 0, starty = 0;
        int loop = n / 2, mid = n / 2;
        int count = 1, offset = 1;
        int i, j;
        vector<vector<int>> res(n, vector(n, 0));
        while (loop--) {
            i = startx;
            j = starty;
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            offset++;
            startx++;
            starty++;
        }
        if(n%2){
            res[mid][mid] = count;
        }
        return res;
    }
};