class Solution {
public:
    vector<vector<int>> ans;
    pair<int,int> move[2] = {{0, 1}, {1, 0}};
    void bfs(pair<int,int> parent, vector<vector<int>>& land){
        int m = land.size(), n = land[0].size();
        land[parent.first][parent.second] = -1;
        vector<int> group;
        group.push_back(parent.first);
        group.push_back(parent.second);
        queue<pair<int,int>> q;
        q.push(parent);
        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();
            bool islast = true;
            for(auto mov : move){
                int next_row = curr.first + mov.first;
                int next_col = curr.second + mov.second;
                if(next_row >= 0 && next_row < m && next_col >= 0 && next_col < n){
                    if(land[next_row][next_col]){
                        islast = false;
                        if(land[next_row][next_col] == 1){
                            land[next_row][next_col] = -1;
                            q.push({next_row, next_col});
                        }
                    }
                }
            }
            if(islast){
                group.push_back(curr.first);
                group.push_back(curr.second);
            }
        }
        ans.push_back(group);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(land[row][col] == 1){
                    bfs({row, col}, land);
                }
            }
        }
        return ans;
    }
};