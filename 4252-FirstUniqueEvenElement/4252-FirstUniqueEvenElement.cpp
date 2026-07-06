// Last updated: 06/07/2026, 11:58:02
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i:nums){
            if(i%2 == 0) freq[i]++;
        }
        for(auto i:nums){
            if(i%2 == 0 && freq[i] == 1) return i; 
        }
        return -1;
    }
};