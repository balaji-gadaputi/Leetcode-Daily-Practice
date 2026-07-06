// Last updated: 06/07/2026, 11:57:59
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(256,0);
        for(char c:s) freq[c]++;
        vector<bool> visited(256,false);
        int ans = 0;
        for(char c:s){
            if(visited[c]) continue;
            char m;
            if(isalpha(c)) m = 'a'+('z'-c);
            else m = '0'+('9'-c);
            ans += abs(freq[c] - freq[m]);
            visited[c] = true; visited[m] = true;
        }
        return ans;
    }
};