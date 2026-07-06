// Last updated: 06/07/2026, 11:58:43
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        function<long long(int, int)> dfs = [&](int i, int j) -> long long {
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
                return 0;

            visited[i][j] = true;
            long long sum = grid[i][j];

            for (auto& [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                sum += dfs(ni, nj);
            }

            return sum;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    long long islandSum = dfs(i, j);
                    if (islandSum % k == 0)
                        ++count;
                }
            }
        }

        return count;
    }
};
