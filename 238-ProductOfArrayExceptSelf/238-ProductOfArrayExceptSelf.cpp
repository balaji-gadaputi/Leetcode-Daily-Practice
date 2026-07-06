// Last updated: 06/07/2026, 11:59:29
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size(),1),prefix(nums.size(),1),product(nums.size()); int prod = 1;
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for(int i=0; i<nums.size(); i++){
            product[i] = suffix[i] * prefix[i];
        }
        return product;
    }
};