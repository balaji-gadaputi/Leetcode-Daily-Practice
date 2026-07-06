// Last updated: 06/07/2026, 12:01:01
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0,k=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i]; index++;
            }
        }
        return index;
    }
};