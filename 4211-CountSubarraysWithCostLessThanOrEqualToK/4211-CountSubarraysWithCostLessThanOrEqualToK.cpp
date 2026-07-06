// Last updated: 06/07/2026, 11:58:20
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> maxele; deque<int> minele;
        long long count = 0; int l = 0, n=nums.size();
        for(int r=0; r<n; r++){
            while(!maxele.empty() && maxele.back()<nums[r]){
                maxele.pop_back();
            }
            maxele.push_back(nums[r]);
            while(!minele.empty() && minele.back()>nums[r]){
                minele.pop_back();
            }
            minele.push_back(nums[r]);
            while(!maxele.empty() && !minele.empty() && (long long)(maxele.front() - minele.front())*(r-l+1)>k){
                if(nums[l] == maxele.front()) maxele.pop_front();
                if(nums[l] == minele.front()) minele.pop_front();
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
};