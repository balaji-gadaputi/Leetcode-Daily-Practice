// Last updated: 06/07/2026, 11:57:56
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        // computing the frequencies for all the elements
        for(int i=0; i<nums1.size(); i++){
            mp[ nums1[i] ]++; mp1[ nums1[i] ]++;
        }
        for(int i=0; i<nums2.size(); i++){
            mp[ nums2[i] ]++; mp2[ nums2[i] ]++;
        }
        for(auto p:mp){
            if(p.second % 2!=0) return -1;
        } unordered_map<int,int> target;
        for(auto p:mp){
            target[p.first] = p.second/2;
        } int surplus=0;
        for(auto p:mp){
            if(mp1[p.first]>target[p.first]){
                surplus += mp1[p.first] - target[p.first]; 
            }
        }
        return surplus;
    }
};