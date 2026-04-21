class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0,r=0;
        vector<int> hash(26,0);
        int ans = 0;
        while(r<n){
            hash[s[r]-'A']++;
            r++;
            int len = r-l;
            int maxi = findMax(hash);
            while((len-maxi)>k){
                hash[s[l]-'A']--;
                maxi = findMax(hash);
                l++;
                len = r-l;
                
            }
            ans = max(ans,len);
        }
        return ans;
    }

    int findMax(vector<int> &hash){
        int maxi = 0;
        for(auto &x: hash) maxi = max(maxi,x);
        return maxi;
    }
};
