class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int n, int r, int c, int expval) {
        if (r < 0 || c < 0 || c >= n || r >= n || grid[r][c] != expval) {
            return false;
        }
        if (expval == (n * n - 1)) {
            return true;
        }
        // 8 moves
        int ans1 = isvalid(grid, n, r - 2, c + 1, expval + 1);
        int ans2 = isvalid(grid, n, r - 1, c + 2, expval + 1);
        int ans3 = isvalid(grid, n, r + 1, c + 2, expval + 1);
        int ans4 = isvalid(grid, n, r + 2, c + 1, expval + 1);
        int ans5 = isvalid(grid, n, r + 2, c - 1, expval + 1);
        int ans6 = isvalid(grid, n, r + 1, c - 2, expval + 1);
        int ans7 = isvalid(grid, n, r - 1, c - 2, expval + 1);
        int ans8 = isvalid(grid, n, r - 2, c - 1, expval + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid, grid.size(), 0, 0, 0);
    }
};