// Last updated: 06/07/2026, 12:00:08
class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<string> path;
        recur(path,0,s); return res;
    }

    void recur(vector<string> path, int start, string s){
        if(start == s.size()){
            res.push_back(path); return;
        }
        for(int end = start; end<s.size(); end++){
            string sub = s.substr(start, end-start+1);
            if(pal(sub)){
                path.push_back(sub);
                recur(path,end+1,s);
                path.pop_back();
            }
        }
    }

    bool pal(string s){
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};