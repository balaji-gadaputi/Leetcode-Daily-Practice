// Last updated: 06/07/2026, 11:59:11
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, i=0,j=0;
        sort(g.begin(),g.end()); sort(s.begin(),s.end());
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                count++; i++; j++;
            }else if(g[i]>s[j]){
                j++;
            }else{
                i++;
            }
        }
        return count;
    }
};