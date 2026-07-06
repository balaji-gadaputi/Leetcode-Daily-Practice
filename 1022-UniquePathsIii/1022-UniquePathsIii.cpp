// Last updated: 06/07/2026, 11:58:57
class Solution {
public:
    int ecnt = 0, m, n;
    int res = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) ecnt++;
                else if (grid[i][j] == 1) { m = i; n = j; }
            }
        }

        // Start the DFS from the starting square (1), count= -1 because we start on a valid cell
        dfs(grid, visited, m, n, -1); 

        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int cnt) {
        int rows = grid.size();
        int cols = grid[0].size();

        // boundary check or invalid cell
        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == -1 || visited[x][y])
            return;

        // if destination is reached
        if (grid[x][y] == 2) {
            if (cnt == ecnt) res++; // if all empty cells + start are visited
            return;
        }

        visited[x][y] = true;

        int dx[] = {-1, 1, 0, 0}; // up, down, left, right
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            dfs(grid, visited, nx, ny, cnt + 1);
        }

        visited[x][y] = false; // backtrack
    }
};
