// Last updated: 06/07/2026, 11:58:21
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size(), min = 0;
        for(int i = n-1; i>0; i--){
            if( nums[i] > nums[i-1] ) continue;
            else {min = i; break;}
        }
        return min;
    }
};