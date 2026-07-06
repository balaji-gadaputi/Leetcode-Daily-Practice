// Last updated: 06/07/2026, 12:01:24
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> substr;
        int l=0,res=0,n=s.length();
        for(int r=0;r<n;r++){
            while (substr.find(s[r])!=substr.end()){
                substr.erase(s[l]);
                l++;
            }
            substr.insert(s[r]);
            res=max(res,(r-l+1));
        }
        return res;
    }
};