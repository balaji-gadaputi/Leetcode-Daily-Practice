// Last updated: 06/07/2026, 12:00:09
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(auto num:s){
            if(s.find(num-1)==s.end()){ // Duplicate check
                int current=num;
                int count=1;
                while(s.find(current+1) != s.end()){
                    current++;count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};