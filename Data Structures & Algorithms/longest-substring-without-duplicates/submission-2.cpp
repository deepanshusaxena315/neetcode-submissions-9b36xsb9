class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0,r= 0;
        unordered_map<char,int> mp;

        while(r<n){
            mp[s[r]]++;
            int len = r-l+1;
            while(len> mp.size()){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
                len = r-l+1;
            }
            len = r-l+1;
            ans = max(ans,len);
            r++;
        }
        return ans;
    }
};
