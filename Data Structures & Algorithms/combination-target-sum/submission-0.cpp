class Solution {
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        recursion(nums,0,target,arr,ans,0);
        return ans;
    }
    void recursion(vector<int> &nums,int idx,int target,vector<int> arr,vector<vector<int>> &ans,int curr){
        if(idx==n) return;
        if(curr==target){
            ans.push_back(arr);
            return;
        }
        if(curr<target){
            arr.push_back(nums[idx]);
            recursion(nums,idx,target,arr,ans,curr+nums[idx]);
            arr.pop_back();
            recursion(nums,idx+1,target,arr,ans,curr);
        }        
    }
};
