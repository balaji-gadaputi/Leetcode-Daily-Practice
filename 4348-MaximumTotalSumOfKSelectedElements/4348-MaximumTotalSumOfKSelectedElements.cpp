// Last updated: 06/07/2026, 11:57:55
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long res=0;
        sort( nums.begin(),nums.end(),greater<int>() );
        for(int i=0; i<k; i++){
            if(mul>0){
                res += (long long)nums[i]*mul;
                mul--;
            }
            else{
                res += nums[i];
            }
        }
        return res;
    }
};