// Last updated: 06/07/2026, 12:01:14
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return res; // mismatch found
                }
            }
            res.push_back(c); // all matched at this position
        }
        return res;
    }
};