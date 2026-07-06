// Last updated: 06/07/2026, 11:59:04
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int n=nums.size(),sum=0,count=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(m.find(sum-k) != m.end()){
                count=count+m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};