class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col]){
                    ans += 4;
                    if(row-1 >= 0 && grid[row-1][col])
                        ans-=2;
                    if(col-1 >= 0 && grid[row][col-1])
                        ans-=2;
                }
            }
        }
        return ans;
    }
};