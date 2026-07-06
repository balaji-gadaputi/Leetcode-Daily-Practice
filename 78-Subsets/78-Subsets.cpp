// Last updated: 06/07/2026, 12:00:27
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> result;
        int index = 0;
        vector<int> temp={};
        recur(nums, res, index,temp);
        for(auto i:res){
            vector<int> temp(i.begin(), i.end());
            result.push_back(temp);
        }
        return result;
    }
    void recur(vector<int>& nums, set<vector<int>> &res, int index, vector<int> &temp){
        if(index == nums.size()){
            res.insert(temp);
            return;
        }
        recur(nums,res,index+1,temp);
        temp.push_back(nums[index]);
        recur(nums,res,index+1,temp);
        temp.pop_back();
    }
};