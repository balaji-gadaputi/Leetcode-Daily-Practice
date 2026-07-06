// Last updated: 06/07/2026, 12:01:03
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0, right=1;
        while(right < nums.size()){
            if(nums[left] == nums[right]) right++;
            else{
                nums[left + 1] = nums[right];
                left++; right++;
            }
            
        }
        return left+1;
    }
};