class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int maxi = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(0,0,text1,text2,dp);
    }

    int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp){
        int n = a.size();
        int m = b.size();
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j] =  1 + solve(i+1,j+1,a,b,dp);
        int skip1 = solve(i+1,j,a,b,dp);
        int skip2 = solve(i,j+1,a,b,dp);
        return  dp[i][j] = max(skip1,skip2);
    }


};
