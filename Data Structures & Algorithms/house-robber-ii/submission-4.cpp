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
        int prev2 = nums[lb];
        int prev1 = max(nums[lb+1],nums[lb]);
        for(int i=2;i<len;i++){
            int curr = max(nums[i+lb] + prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
