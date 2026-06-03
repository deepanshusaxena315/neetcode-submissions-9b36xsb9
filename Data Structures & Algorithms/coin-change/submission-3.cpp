class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        vector<int> dp(amount+1,-1);
        int ans = solve(amount,coins,dp);
        return ans == INT_MAX ? -1 : ans;
    }

    int solve(int amt,vector<int> &coins,vector<int> &dp){
        int n = coins.size();
        if(amt==0) return 0;
        if(amt<0) return INT_MAX;
        if(dp[amt]!=-1) return dp[amt];

        int res = INT_MAX;
        for(auto &coin: coins){
            int take = solve(amt-coin,coins,dp);
            if(take!=INT_MAX) res = min(res,1 + take);
        }
        return dp[amt] = res;
    }


};
