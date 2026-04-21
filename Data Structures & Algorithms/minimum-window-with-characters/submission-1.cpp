class Solution {
public:
    string minWindow(string s, string t) {
        int n= t.size();
        int l=0,r=0;
        unordered_map<char,int> freq;
        for(auto &ch:t) freq[ch]++;
        int cnt = 0;
        int minL = INT_MAX;
        int start = -1;
        while(r<s.size()){
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;
            while(cnt==t.size()){
                if(minL>(r-l+1)){
                    minL = r-l+1;
                    start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(start==-1) return "";
        return s.substr(start,minL);
    }
};
