class Solution {
public:
    int n, m;
    int del[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Pacific: top row
        for(int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
        }

        // Pacific: left column
        for(int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Atlantic: bottom row
        for(int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atlantic);
        }

        // Atlantic: right column
        for(int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        vis[r][c] = 1;

        for(int k = 0; k < 4; k++) {
            int nr = r + del[k][0];
            int nc = c + del[k][1];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

};
