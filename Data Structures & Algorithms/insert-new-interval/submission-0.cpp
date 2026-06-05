class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        for(int i=0;i<n;i++){
            if(intervals[i][1]<start){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]> end){
                ans.push_back({start,end});

                while(i<n){
                    ans.push_back(intervals[i]);
                    i++;
                }
                return ans;
            }
            else{
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
        }

        ans.push_back({start,end});
        return ans;
    }
};
