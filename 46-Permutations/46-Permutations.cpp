// Last updated: 06/07/2026, 12:00:49
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        recur(nums, 0,n);
        return res;
    }
    void recur(vector<int> &nums, int index, int n){
        if(index == n){ res.push_back(nums); return; }
        for(int i = index; i<n; i++){
            swap(nums[index], nums[i]);
            recur(nums, index+1, n);
            swap(nums[index], nums[i]);
        }
    }
};