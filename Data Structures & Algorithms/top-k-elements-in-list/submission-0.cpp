class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        unordered_map<int,int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        for(auto &a: mp){
            v.push_back({a.second,a.first});
        }
        sort(v.begin(),v.end());
        int n = v.size();
        vector<int> ans;
        for(int i=n-1;i>n-k-1;i--){
            
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
