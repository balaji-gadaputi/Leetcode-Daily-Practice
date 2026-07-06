// Last updated: 06/07/2026, 11:59:06
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low = 0, high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(mid%2 == 0){ // odd
                if(nums[mid] == nums[mid+1]) low = mid+2;
                else high = mid;
            }else{ // even
                if(nums[mid] == nums[mid-1]) low = mid+1;
                else high = mid;
            }
        }
        return nums[low];
    }
};