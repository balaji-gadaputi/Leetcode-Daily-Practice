// Last updated: 06/07/2026, 12:01:28
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(m.find(diff) != m.end() ){
                res.push_back(i);res.push_back(m[diff]);break;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};