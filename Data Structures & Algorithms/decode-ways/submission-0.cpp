class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }

    int solve(int idx,string &s,vector<int> &dp){
        int n = s.size();
        if(dp[idx]!=-1) return dp[idx];
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        int ans= solve(idx+1,s,dp);
        if(idx+1<n){
            int num = (s[idx]-'0')*10 + (s[idx+1]-'0');
            if((num<=26 && num>=10))ans += solve(idx+2,s,dp);
        }
        return dp[idx] = ans;
        
    }
};
