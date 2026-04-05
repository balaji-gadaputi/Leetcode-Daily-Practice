// Last updated: 05/04/2026, 09:05:37
1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        vector<int> freq(256,0);
5        for(char c:s) freq[c]++;
6        vector<bool> visited(256,false);
7        int ans = 0;
8        for(char c:s){
9            if(visited[c]) continue;
10            char m;
11            if(isalpha(c)) m = 'a'+('z'-c);
12            else m = '0'+('9'-c);
13            ans += abs(freq[c] - freq[m]);
14            visited[c] = true; visited[m] = true;
15        }
16        return ans;
17    }
18};