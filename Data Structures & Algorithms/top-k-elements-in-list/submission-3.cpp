class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        for(auto &a: mp){
            pq.push({a.second,a.first});
            if(pq.size()>k) pq.pop();
        }
        
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
