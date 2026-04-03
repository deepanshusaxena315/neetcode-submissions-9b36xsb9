class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x: nums) st.insert(x);
        return st.size()!=nums.size();
    }
};