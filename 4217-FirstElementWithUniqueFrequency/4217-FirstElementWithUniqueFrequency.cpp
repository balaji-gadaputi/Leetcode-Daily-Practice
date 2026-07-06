// Last updated: 06/07/2026, 11:58:13
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp; int n = nums.size();
        unordered_map<int,int> freq;
        
        for(int i=0; i<n; i++) mp[ nums[i] ]++;
        for(auto i : mp) freq[i.second]++;

        for(auto i : nums){
            if(freq[mp[i]] == 1) return i;
        }
        return -1;
    }
};