/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> i;
        for(auto &meeting: intervals){
            i.push_back({meeting.start,meeting.end});
        }
        sort(i.begin(),i.end());
        int end = i[0][1];
        for(int j=1;j<i.size();j++){
            int nextStart = i[j][0];
            if(nextStart<end){
                return false;
            }
            else{
                end = i[j][1];
            }
        }
        return true;
    }
};
