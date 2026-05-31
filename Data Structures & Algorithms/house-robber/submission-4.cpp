class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];

        // vector<int> dp(n,-1);
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        int curr = 0;
        for(int i=2;i<n;i++){
            int rob = nums[i] + prev1;
            int leave = prev2;
            curr = max(rob,leave);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    // int recursion(vector<int> &nums,int house,vector<int> &dp){
    //     if(house <0) return 0;
    //     if(dp[house]!=-1) return dp[house];
    //     int take = (nums[house] + recursion(nums,house-2,dp));
    //     int notTake = recursion(nums,house-1,dp);
    //     return dp[house] = max(take,notTake);
    // }
};
