// Last updated: 06/07/2026, 11:59:13
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int count = 0;
        int prevend = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prevend) count++;
            else prevend=intervals[i][1];
        }
        return count;
    }
};