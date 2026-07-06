// Last updated: 06/07/2026, 11:59:48
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<nums[mid+1]) l = mid+1;
            else r = mid;
        }
        return l;
    }
};