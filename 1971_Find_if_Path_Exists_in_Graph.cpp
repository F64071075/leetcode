class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& adjlist, vector<bool>& visited){
        visited[src] = true;
        bool haspath = false;
        for(auto neighbor : adjlist[src]){
            if(neighbor == dest)
                return true;
            if(!visited[neighbor]){
                haspath |= dfs(neighbor, dest, adjlist, visited);
            }
        }
        return haspath;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1)  return true;
        vector<vector<int>> adjlist(n);
        for(auto edge : edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, adjlist, visited);
    }
};