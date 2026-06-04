class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int val = 0;
                if(i-1>=0) val += dp[i-1][j];
                if(j-1>=0) val+= dp[i][j-1];
                dp[i][j] = val;
            }
        }
        return dp[m-1][n-1];
        return solve(0,0,m,n,dp);
    }

    int solve(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = 0;
        int down = 0;
        if(i+1<m) down = solve(i+1,j,m,n,dp);
        if(j+1<n) right = solve(i,j+1,m,n,dp);
        return dp[i][j]  = down + right;
    }
};
