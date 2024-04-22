class Solution {
public:
    int bfs(unordered_set<string>& u_set, string target){
        vector<bool> visited(10000, false);
        visited[0] = true;
        queue<string> q;
        q.push("0000");
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                string curr = q.front(); q.pop();
                for(int i = 0; i < curr.size(); i++){
                    for(int j = 1; j >= -1; j-=2){
                        string neighbor = curr;
                        int ascii = (int)neighbor[i] + j;
                        if(ascii > (int)'9')
                            ascii -= 10;
                        else if(ascii < (int)'0')
                            ascii += 10;
                        neighbor[i] = (char)ascii;
                        if(neighbor == target)
                            return ans;
                        if(!u_set.count(neighbor) && !visited[stoi(neighbor)]){
                            visited[stoi(neighbor)] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        int cnt = 0;
        if(target == "0000")
            return 0;
        unordered_set<string> u_set;
        for(auto str : deadends){
            if(str == "0000")
                return -1;
            u_set.insert(str);
        }
        return bfs(u_set, target);
    }
};