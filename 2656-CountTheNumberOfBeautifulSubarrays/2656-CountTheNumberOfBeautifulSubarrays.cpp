// Last updated: 06/07/2026, 11:58:49
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = 1;
        int curxor = 0;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            curxor ^= nums[i];
            if (m.find(curxor) != m.end()) {
                count += m[curxor];
            }
            m[curxor]++;
        }
        return count;
    }
};
