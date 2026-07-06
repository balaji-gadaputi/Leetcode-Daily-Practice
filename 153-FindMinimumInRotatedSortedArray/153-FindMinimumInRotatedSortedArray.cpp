// Last updated: 06/07/2026, 11:59:51
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min;
        if(is_sorted(nums.begin(),nums.end())) return nums[0];
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) min = nums[i+1];
        }
        return min;
    }
};