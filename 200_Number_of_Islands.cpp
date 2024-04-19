class Solution {
public:
    int ans = 0;
    const pair<int, int> move[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(pair<int, int> curr, vector<vector<char>>& grid) {
        auto [row, col] = curr;
        int m = grid.size(), n = grid[0].size();
        grid[row][col] = '0';
        for (auto mov : move) {
            int next_row = row + mov.first;
            int next_col = col + mov.second;
            if (next_row >= 0 && next_row < m && next_col >= 0 &&
                next_col < n) {
                if (grid[next_row][next_col] == '1') {
                    grid[next_row][next_col] = '0';
                    dfs({next_row, next_col}, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    ans++;
                    dfs({row, col}, grid);
                }
            }
        }
        return ans;
    }
};