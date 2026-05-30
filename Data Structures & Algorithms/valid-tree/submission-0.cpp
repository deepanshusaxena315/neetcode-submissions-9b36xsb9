class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        if(dfs(0,adj,visited,-1)) return false;
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &visited,int prev){
        visited[node] = 1;
        for(auto &neighbor: adj[node]){
            if(visited[neighbor] && prev!=neighbor) return true;
            else if(!visited[neighbor]){
                if(dfs(neighbor,adj,visited,node)==true) return true;
            }
        }
        return false;
    }
};
