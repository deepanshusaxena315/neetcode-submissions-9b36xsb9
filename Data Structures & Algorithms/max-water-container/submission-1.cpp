class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int l =0,r=n-1;
        while(l<r){
            int minh = min(heights[l],heights[r]);
            ans = max(ans,(r-l)*minh);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
