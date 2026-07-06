// Last updated: 06/07/2026, 11:59:19
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        for(auto i:nums1) s1.insert(i);
        for(auto i:nums2) s2.insert(i);
        vector<int> res;
        for(auto i:s1){
            if(s2.count(i)) res.push_back(i);
        }
        return res;
    }
};