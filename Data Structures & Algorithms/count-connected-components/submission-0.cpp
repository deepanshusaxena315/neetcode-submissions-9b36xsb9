class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,-1);
                ans++;
            }
        }
        return ans;
    }

    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited,int parent){
        visited[node] =1;
        for(auto &n: adj[node]){
            if(!visited[n]){
                dfs(n,adj,visited,node);
            }
        }
        return;
    }
};
