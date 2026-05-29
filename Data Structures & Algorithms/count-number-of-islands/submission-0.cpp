class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    ans ++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        visited[r][c] = 1;
        vector<vector<int>> del = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &d:del){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc]){
                dfs(grid,visited,nr,nc);
            }
        }

    }
};
