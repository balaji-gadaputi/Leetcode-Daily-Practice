// Last updated: 06/07/2026, 12:00:20
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), index = 0;
        vector<int> path = {};
        recur(nums, res, n, index, path);
        return res;
    }
    void recur(vector<int> &nums, vector<vector<int>> &res, 
              int n, int index, vector<int> path){
        res.push_back(path);
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            recur(nums, res, n, i+1, path);
            path.pop_back();
        }
    }
};