// Last updated: 04/04/2026, 15:15:25
1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        vector<vector<int>> res;
5
6        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, 
7        const vector<int>&b){
8            return a[0] < b[0];
9        }); // sorting intervals according to start time
10        int cur_start = intervals[0][0];
11        int cur_end = intervals[0][1];
12
13        for(int i=1; i<intervals.size(); i++){
14
15            if( cur_end >= intervals[i][0] ){ // Overlapping intervals
16                cur_end = max(cur_end,intervals[i][1]);
17            }
18            else{
19                res.push_back( {cur_start,cur_end} );
20                cur_start = intervals[i][0];
21                cur_end = intervals[i][1];
22            }
23        }
24        res.push_back( {cur_start,cur_end} );
25        return res;
26    }
27};