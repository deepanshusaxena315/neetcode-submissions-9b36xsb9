class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(solve(0,n-2,nums,dp1),solve(1,n-1,nums,dp2));
    }

    int solve(int lb,int i,vector<int> &nums,vector<int> &dp){
        if(i<lb) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + solve(lb,i-2,nums,dp);
        int skip = solve(lb,i-1,nums,dp);
        return dp[i] = max(rob,skip);
    }
};
