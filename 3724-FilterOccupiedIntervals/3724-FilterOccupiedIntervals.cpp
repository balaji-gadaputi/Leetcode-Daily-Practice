// Last updated: 06/07/2026, 11:58:44
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> res,ans;
        sort(occupiedIntervals.begin(), occupiedIntervals.end(), [](const std::vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int start = occupiedIntervals[0][0],end=occupiedIntervals[0][1];
        for(int i=0; i<occupiedIntervals.size()-1; i++){
            if(end + 1 >= occupiedIntervals[i+1][0]){
                end = max(end,occupiedIntervals[i+1][1]);
            } else{
                res.push_back({start,end});
                start = occupiedIntervals[i+1][0];
                end = occupiedIntervals[i+1][1];
            }
        }
        res.push_back({start,end});
        for(int i=0; i<res.size(); i++){
            int start = res[i][0], end = res[i][1];
            if(end < freeStart || start > freeEnd){
                ans.push_back({start,end});
            }
            else{
                if(start<freeStart){
                    ans.push_back({start,freeStart-1});
                }
                if(end>freeEnd){
                    ans.push_back({freeEnd+1,end});
                }
            }
        }
        return ans;
    }
};