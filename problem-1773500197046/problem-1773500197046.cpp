// Last updated: 14/03/2026, 20:26:37
1class Solution {
2public:
3    int firstUniqueEven(vector<int>& nums) {
4        unordered_map<int,int> freq;
5        for(auto i:nums){
6            if(i%2 == 0) freq[i]++;
7        }
8        for(auto i:nums){
9            if(i%2 == 0 && freq[i] == 1) return i; 
10        }
11        return -1;
12    }
13};