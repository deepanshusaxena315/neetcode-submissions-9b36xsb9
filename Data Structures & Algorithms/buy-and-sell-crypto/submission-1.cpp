class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n =prices.size();
        int buying = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i] - buying;
            ans = max(ans,profit);
            buying = min(buying,prices[i]);
        }
        return ans;
    }
};
