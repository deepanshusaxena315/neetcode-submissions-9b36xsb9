class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int maxi = 0;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = 
                        max(prev[j],curr[j-1]);
                }
                
            }
            prev = curr;
        }
        return curr[m];
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
