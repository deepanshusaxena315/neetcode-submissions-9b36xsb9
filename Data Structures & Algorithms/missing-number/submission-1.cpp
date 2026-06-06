class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n  = nums.size();
        int xorVal = 0;
        for(int i=0;i<=n;i++){
            xorVal = xorVal^i;
        }
        for(auto &num: nums){
            xorVal = xorVal^num;
        }
        return xorVal;
    }
};
