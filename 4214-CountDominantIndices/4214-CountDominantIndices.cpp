// Last updated: 06/07/2026, 11:58:15
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(),count = 0;
        for(int i=0; i<n-1; i++){
            int avg = 0,j=i+1;
            for(j=i+1; j<n; j++){
                avg += nums[j];
            }
            avg /= j-i-1;
            if(nums[i] > avg) count++;
        }
        return count;
    }
};