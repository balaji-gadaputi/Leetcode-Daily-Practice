// Last updated: 06/07/2026, 11:58:56
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n); // adjacency list
        for (auto& path : paths) {
            adj[path[0] - 1].push_back(path[1] - 1);
            adj[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int> res(n, 0); // flower type assigned to each garden

        for (int i = 0; i < n; ++i) {
            bool used[5] = {false}; // flower types 1 to 4

            for (int neighbor : adj[i]) {
                if (res[neighbor] != 0) {
                    used[res[neighbor]] = true; // mark neighbor's flower as used
                }
            }

            // assign the first available flower
            for (int f = 1; f <= 4; ++f) {
                if (!used[f]) {
                    res[i] = f;
                    break;
                }
            }
        }

        return res;
    }
};
