// Last updated: 06/07/2026, 11:58:10
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size(); vector<long long> suffix(n,1), prefix(n,0);
        long long maxsum = 0;
        for(int x:nums) maxsum+=x;
        
        for(int i=n-2; i>=0; i--){
            if( (suffix[i+1]>maxsum) || nums[i+1] != 0 && suffix[i+1] > maxsum/nums[i+1]) suffix[i] = maxsum+1;
            else{
                suffix[i] = suffix[i+1] * nums[i+1];
            }
        }
        
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i=0; i<n; i++){
            if(suffix[i] == prefix[i]) return i;
        }
        return -1;
    }
};

/*
suffix product
prefix sum
*/