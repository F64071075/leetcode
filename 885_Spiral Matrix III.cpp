class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> arr;
        pair<int,int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cnt = 1;
        int turn = 1;
        int dirIdx = 0;
        arr.push_back({rStart, cStart});
        if(rows == 1 && cols == 1)
            return arr;
        pair<int,int> prev = {rStart, cStart};
        while(true){
            int fixTurn = 2;
            while(fixTurn--){
                int tcnt = turn;
                while(tcnt--){
                    auto curr = make_pair(prev.first+dir[dirIdx].first, prev.second+dir[dirIdx].second);
                    if(curr.first >= 0 && curr.first < rows && curr.second >= 0 && curr.second < cols){
                        // cout << curr.first << " " << curr.second << endl;
                        arr.push_back({curr.first, curr.second});
                        if(++cnt == rows*cols)
                            return arr;
                    }
                    prev = curr;
                }
                dirIdx = (dirIdx+1)%4;
            }
            turn++;
        }
        return arr;
    }
};