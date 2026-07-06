// Last updated: 06/07/2026, 11:58:40
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        using T = tuple<long long, int, int, int>; // (cost, i, j, second % 2)

        vector<vector<int>> entryCost(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                entryCost[i][j] = (i + 1) * (j + 1);

        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][1] = entryCost[0][0];
        pq.emplace(entryCost[0][0], 0, 0, 1); // start at second 1

        while (!pq.empty()) {
            auto [cost, i, j, sec] = pq.top(); pq.pop();
            if (i == m - 1 && j == n - 1) return cost;

            int nextSec = sec + 1;
            int parity = nextSec % 2;

            // Wait in place
            if (cost + waitCost[i][j] < dist[i][j][parity]) {
                dist[i][j][parity] = cost + waitCost[i][j];
                pq.emplace(cost + waitCost[i][j], i, j, nextSec);
            }

            // Move to adjacent (only on odd seconds)
            if (sec % 2 == 1) {
                if (i + 1 < m) {
                    long long newCost = cost + entryCost[i + 1][j];
                    if (newCost < dist[i + 1][j][parity]) {
                        dist[i + 1][j][parity] = newCost;
                        pq.emplace(newCost, i + 1, j, nextSec);
                    }
                }
                if (j + 1 < n) {
                    long long newCost = cost + entryCost[i][j + 1];
                    if (newCost < dist[i][j + 1][parity]) {
                        dist[i][j + 1][parity] = newCost;
                        pq.emplace(newCost, i, j + 1, nextSec);
                    }
                }
            }
        }

        return -1; // shouldn't reach here
    }
};
