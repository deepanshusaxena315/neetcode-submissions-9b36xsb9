class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        // vector<int> dp(n+1,-1);
        
        // dp[1] = 1;
        // dp[2] = 2;
        int curr = 2;
        int prev = 1;
        int ans= 0;
        for(int i=3;i<=n;i++){
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
        // return ways(n,dp);

    }

    int ways(int n,vector<int> &dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = ways(n-1,dp) + ways(n-2,dp);

    }
};
