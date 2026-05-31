class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int rob = nums[i] + dp[i-2];
            int leave = dp[i-1];
            dp[i] = max(rob,leave);
        }
        return dp[n-1];
    }

    // int recursion(vector<int> &nums,int house,vector<int> &dp){
    //     if(house <0) return 0;
    //     if(dp[house]!=-1) return dp[house];
    //     int take = (nums[house] + recursion(nums,house-2,dp));
    //     int notTake = recursion(nums,house-1,dp);
    //     return dp[house] = max(take,notTake);
    // }
};
