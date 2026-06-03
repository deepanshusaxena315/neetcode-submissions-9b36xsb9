class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector(n+1,-1));
        return solve(0,0,s,wordDict,dp);
    }

    bool solve(int prev,int curr,string &s,vector<string> &wordDict,vector<vector<int>> & dp){
        int n = s.size();
        if(curr>n) return false;
        if(curr==n && prev==n) return true;
        if(dp[prev][curr]!=-1) return dp[prev][curr];
        string subs = s.substr(prev,curr-prev+1);
        bool isThere = false;
        for(auto &str: wordDict){
            if(str==subs){
                isThere = true;
                break;
            }
        }
        bool ans = false;
        if(isThere){
           ans = ans || solve(curr+1,curr+1,s,wordDict,dp);
        }
        return dp[prev][curr] = ans || solve(prev,curr+1,s,wordDict,dp);
    }
};
