class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l =0,r = n-1;
        int mid = 0;
        
        while(l<r){
            mid = (l)+(r-l)/2;
            if(nums[mid] < nums[r]){
                r=mid;
                
            }
            else if(nums[l]<=nums[mid]){
                l = mid+1;
            }
        }

        return nums[l];
    }
};
