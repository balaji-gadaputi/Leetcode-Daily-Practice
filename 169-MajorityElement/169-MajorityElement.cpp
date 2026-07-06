// Last updated: 06/07/2026, 11:59:47
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(int i:nums){
            if(m[i]> nums.size()/2){
                return i;
            }
        }
        return -1;
    }
};