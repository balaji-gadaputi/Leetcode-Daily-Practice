// Last updated: 10/03/2026, 15:23:51
1class Solution {
2public:
3    vector<int> dp; int maxlen;
4    bool wordBreak(string s, vector<string>& wordDict) {
5      unordered_set<string> dict(wordDict.begin(), wordDict.end());
6        dp.assign(s.size(),-1); maxlen = 0;
7        for(auto &word:wordDict) maxlen = max(maxlen,(int)word.size());
8        return solve(0,s,dict);
9    }
10    bool solve(int i, string &s, unordered_set<string> &dict){
11        if(i == s.size()) return true;
12        if(dp[i] != -1) return dp[i];
13        
14        for(int j=i; j<s.size() && (j-i+1)<=maxlen; j++){
15            string temp = s.substr(i,j-i+1);
16            if(dict.count(temp)){
17                if(solve(j+1, s, dict)) return dp[i] = 1;
18            }
19        }
20        return dp[i] = 0;
21    }
22};