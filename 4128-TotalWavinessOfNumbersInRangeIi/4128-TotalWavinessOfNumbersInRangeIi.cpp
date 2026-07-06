// Last updated: 06/07/2026, 11:58:27
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        if (num1 == 0) return solve(num2);
        return solve(num2) - solve(num1 - 1);
    }

private:
    string s;
    int len;
    long long dpCnt[20][11][11][2][2];
    long long dpWav[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<long long, long long> dfs(int pos, int last2, int last1, int tight, int started) {
        if (pos == len) {
            if (!started) return {1, 0};
            return {1, 0};
        }

        if (vis[pos][last2][last1][tight][started]) {
            return {dpCnt[pos][last2][last1][tight][started],
                    dpWav[pos][last2][last1][tight][started]};
        }

        int limit = tight ? (s[pos] - '0') : 9;
        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                auto sub = dfs(pos + 1, 10, 10, ntight, 0);
                totalCnt += sub.first;
                totalWav += sub.second;
            } else if (!started) {
                auto sub = dfs(pos + 1, 10, d, ntight, 1);
                totalCnt += sub.first;
                totalWav += sub.second;
            } else {
                int added = 0;
                if (last2 != 10) {
                    if ((last1 > last2 && last1 > d) || (last1 < last2 && last1 < d)) {
                        added = 1;
                    }
                }
                auto sub = dfs(pos + 1, last1, d, ntight, 1);
                totalCnt += sub.first;
                totalWav += sub.second + 1LL * added * sub.first;
            }
        }

        vis[pos][last2][last1][tight][started] = true;
        dpCnt[pos][last2][last1][tight][started] = totalCnt;
        dpWav[pos][last2][last1][tight][started] = totalWav;

        return {totalCnt, totalWav};
    }

    long long solve(long long N) {
        if (N < 0) return 0;
        s = to_string(N);
        len = (int)s.size();
        memset(vis, 0, sizeof(vis));
        auto res = dfs(0, 10, 10, 1, 0);
        return res.second;
    }
};
