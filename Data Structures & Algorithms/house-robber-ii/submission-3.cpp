class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }

    int solve(int lb,int ub,vector<int> &nums){
        int len = ub-lb + 1;
        if(len ==1) return nums[lb];
        vector<int> dp(len,-1);
        dp[0] = nums[lb];
        dp[1] = max(nums[lb+1],nums[lb]);
        for(int i=2;i<len;i++){
            dp[i] = max(dp[i-1],nums[lb + i] + dp[i-2]);
        }
        return dp[len-1];
    }
};
