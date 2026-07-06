// Last updated: 06/07/2026, 11:58:24
class Solution {
public:
    string reversePrefix(string s, int k) {
      string pre = s.substr(0,k);
      string suff = s.substr(k, (s.length() - k));
      reverse(pre.begin(),pre.end());
      string res = pre + suff;
      return res;
    }
};