class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n =prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int profit = prices[j]-prices[i];
                ans = max(ans,profit);
            }
        }
        return ans;
    }
};
