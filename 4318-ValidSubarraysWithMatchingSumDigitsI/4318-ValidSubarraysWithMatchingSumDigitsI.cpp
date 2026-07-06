// Last updated: 06/07/2026, 11:57:58
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int res = 0;
        for(int l=0; l<nums.size(); l++){
            long long sum = 0;
            for(int r=l; r<nums.size(); r++){
                sum += nums[r];
                int lastdig = sum%10;
                long long firstdig = sum;
                while (firstdig >= 10)
                    firstdig /= 10;
                if(firstdig == x && lastdig == x)
                    res++;
            }
        }
        return res;
    }
};