class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;//value,idx
        int n = nums.size();
        for(int i=0;i<=n-1;i++){
            int complement = target-nums[i];
            if(mp.count(complement)) return {mp[complement],i};

            mp[nums[i]]  = i;
        }
        return {};
    }
};
