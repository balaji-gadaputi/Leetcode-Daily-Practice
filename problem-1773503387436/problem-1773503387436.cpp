// Last updated: 14/03/2026, 21:19:47
1class Solution {
2public:
3    int minCost(vector<int>& nums1, vector<int>& nums2) {
4        unordered_map<int,int> mp; unordered_map<int,int> mp1;
5        unordered_map<int,int> mp2;
6        // computing the frequencies for all the elements
7        for(int i=0; i<nums1.size(); i++){
8            mp[ nums1[i] ]++; mp1[ nums1[i] ]++;
9        }
10        for(int i=0; i<nums2.size(); i++){
11            mp[ nums2[i] ]++; mp2[ nums2[i] ]++;
12        }
13        for(auto p:mp){
14            if(p.second % 2!=0) return -1;
15        } unordered_map<int,int> target;
16        for(auto p:mp){
17            target[p.first] = p.second/2;
18        } int surplus=0;
19        for(auto p:mp){
20            if(mp1[p.first]>target[p.first]){
21                surplus += mp1[p.first] - target[p.first]; 
22            }
23        }
24        return surplus;
25    }
26};