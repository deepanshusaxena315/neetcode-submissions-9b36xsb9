class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path) == false) return false;
            }
        }
        return true;

    }
    bool dfs(int i,vector<vector<int>> &adj,vector<int> &visited,vector<int> &path){
        auto neighbors = adj[i];
        visited[i] = 1;
        path[i] = 1;
        
        for(auto neighbor: neighbors){
            if(visited[neighbor] && path[neighbor]) return false;
            else if(visited[neighbor]){
                continue;
            }
            else{
                if(dfs(neighbor,adj,visited,path)==false) return false;
            }
        }
        path[i] = 0;
        return true;
    }

};
