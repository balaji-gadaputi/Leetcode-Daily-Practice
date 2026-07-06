// Last updated: 06/07/2026, 11:58:47
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xor1 = 0, xor2 = 0, rep;
        int n = grid.size(), m = grid[0].size();
        vector<int> result;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                xor1 ^= grid[i][j];
                freq[grid[i][j]]++;
                if (freq[grid[i][j]] == 2) rep = grid[i][j];
            }

        for (int i = 1; i <= n * m; ++i)
            xor2 ^= i;

        int miss = (xor1 ^ xor2) ^ rep;
        result.push_back(rep);
        result.push_back(miss);
        return result;
    }
};
