class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);
        return ans == INT_MAX ? -1 : ans;
    }

    int solve(int i,int amt,vector<int> &coins,vector<vector<int>> &dp){
        int n = coins.size();
        if(amt==0) return 0;
        if(amt<0 || i==n) return INT_MAX;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int take = INT_MAX;
        int res = solve(i,amt-coins[i],coins,dp);
        if(res!=INT_MAX){
            take = 1 + res;
        }
        int skip = solve(i+1,amt,coins,dp);
        return dp[i][amt] = min(take,skip);
    }


};
