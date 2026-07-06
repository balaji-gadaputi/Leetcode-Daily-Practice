// Last updated: 06/07/2026, 12:00:57
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[low]<=nums[mid]){ // left half is sorted
                if(target<nums[mid] && target>=nums[low]) high = mid-1;
                else low = mid+1;
            }
            else{ // right half is sorted
                if(target>nums[mid] && target<=nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};