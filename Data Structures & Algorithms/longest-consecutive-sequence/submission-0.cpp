class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxlen = 0;
        int len =0;
        for(auto &num: st){
            if(st.find(num-1)!=st.end()) continue;
            if(st.find(num-1)==st.end()){
                int len = 1;
                int curr = num;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};
