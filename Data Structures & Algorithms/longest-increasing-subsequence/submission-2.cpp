class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }

    int solve(int idx,int j,vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(idx>=n) return 0;
        if(dp[idx][j+1]!=-1) return dp[idx][j+1];
        int curr=  nums[idx];
        int ans = 0;
        if(j==-1 || curr>nums[j]){
            ans += 1+ solve(idx+1,idx,nums,dp);
        }
        ans = max(ans,solve(idx+1,j,nums,dp));
        return dp[idx][j+1] = ans;

    }
};
