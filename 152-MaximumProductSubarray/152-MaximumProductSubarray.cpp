// Last updated: 06/07/2026, 11:59:52
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), mmin=nums[0], mmax=nums[0];
        int lar=nums[0],prod=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<0) swap(mmax, mmin);
            mmax = max(nums[i], nums[i]*mmax);
            mmin = min(nums[i], nums[i]*mmin);
            if(mmax>lar) lar = mmax;
        }
        return lar;
    }
};