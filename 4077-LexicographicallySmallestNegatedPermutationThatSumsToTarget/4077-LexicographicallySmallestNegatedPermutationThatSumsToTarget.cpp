// Last updated: 06/07/2026, 11:58:31
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
       long long T = 1LL * n * (n + 1) / 2;
        if (target < -T || target > T) return {};
        if ((T - target) & 1) return {};

        long long taverniloq = target;

        long long needNeg = (T - taverniloq) / 2;
        vector<char> isNeg(n + 1, 0);

        for (int k = n; k >= 1 && needNeg > 0; --k) {
            if (needNeg >= k) {
                isNeg[k] = 1;
                needNeg -= k;
            }
        }
        if (needNeg != 0) return {};

        vector<int> ans;
        ans.reserve(n);

        for (int k = n; k >= 1; --k) {
            if (isNeg[k]) ans.push_back(-k);
        }
        for (int k = 1; k <= n; ++k) {
            if (!isNeg[k]) ans.push_back(k);
        }

        return ans;
    }
};