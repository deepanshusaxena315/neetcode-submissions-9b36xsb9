class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        // return ways(n,dp);

    }

    int ways(int n,vector<int> &dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = ways(n-1,dp) + ways(n-2,dp);

    }
};
