// Last updated: 06/07/2026, 11:58:37
class Solution {
public:
    vector<int> depth;
    long long dp[65][65][2];

    int computeDepth(int x) {
        if (x == 1) return 0;
        if (depth[x] != -1) return depth[x];
        return depth[x] = 1 + computeDepth(__builtin_popcount(x));
    }

    long long countWays(int pos, int onesLeft, bool tight, vector<int>& bits) {
        if (pos == bits.size()) return onesLeft == 0;
        if (onesLeft < 0) return 0;
        if (dp[pos][onesLeft][tight] != -1) return dp[pos][onesLeft][tight];

        int limit = tight ? bits[pos] : 1;
        long long ways = 0;

        for (int bit = 0; bit <= limit; ++bit) {
            ways += countWays(pos + 1, onesLeft - bit, tight && (bit == limit), bits);
        }

        return dp[pos][onesLeft][tight] = ways;
    }

    long long popcountDepth(long long n, int k) {
        depth = vector<int>(100, -1);
        for (int i = 1; i < 100; ++i) computeDepth(i);

        if (k == 0) {
            return (n >= 1) ? 1 : 0;
        }

        if (n == 0) return 0;

        vector<int> bits;
        long long temp_n = n;
        while (temp_n > 0) {
            bits.push_back(temp_n % 2);
            temp_n /= 2;
        }
        reverse(bits.begin(), bits.end());

        long long result = 0;

        for (int ones = 1; ones <= 63; ++ones) {
            if (computeDepth(ones) == k - 1) {
                memset(dp, -1, sizeof(dp));
                result += countWays(0, ones, true, bits);
            }
        }

        if (k == 1 && n >= 1) {
            result--;
        }

        return result;
    }
};