// Last updated: 06/07/2026, 12:00:44
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), largest = nums[0], sum = nums[0];
        for(int i=1; i<n; i++){
            sum += nums[i];
            if(nums[i]>sum) sum = nums[i];
            if(sum>largest) largest = sum;
        }
        return largest;
    }
};