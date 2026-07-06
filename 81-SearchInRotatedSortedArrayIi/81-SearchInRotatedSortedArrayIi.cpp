// Last updated: 06/07/2026, 12:00:23
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
        Find the pivot, Apply binary search on the two sorted arrays
        */
        if(nums.size() == 1){
            if(nums[0] == target) return true;
            else return false;
        }
        int pivot = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) pivot = (i+1);
        }
        if(pivot == -1){
            int l = 0, r = nums.size()-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums[mid] == target) return true;
                else if(nums[mid]>target) r = mid-1;
                else if(nums[mid]<target) l = mid+1;
            }
            return false;
        }
        int l1=0, r1=pivot-1;
        while (l1<=r1){
            int mid = l1 + (r1-l1)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) r1 = mid-1;
            else if(nums[mid] < target) l1 = mid+1;
        }
        int l2=pivot, r2=nums.size()-1;
        while (l2<=r2){
            int mid = l2 + (r2-l2)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) r2 = mid-1;
            else if(nums[mid] < target) l2 = mid+1;
        }
        return false;
    }
};