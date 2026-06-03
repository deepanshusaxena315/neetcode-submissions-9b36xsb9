class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(0,amount,coins);
        return ans == INT_MAX ? -1 : ans;
    }

    int solve(int i,int amt,vector<int> &coins){
            int n = coins.size();
    if(amt==0) return 0;
    if(amt<0 || i==n) return INT_MAX;

    int take = INT_MAX;
    int res = solve(i,amt-coins[i],coins);
    if(res!=INT_MAX){
        take = 1 + res;
    }
    int skip = solve(i+1,amt,coins);
    return min(take,skip);
    }


};
