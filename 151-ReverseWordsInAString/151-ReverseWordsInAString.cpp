// Last updated: 06/07/2026, 11:59:54
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words; string res;
        for(int i=0; i<s.size(); i++){
            string temp; int flag=0;
            while(s[i]!=' ' && i<s.size()){
                temp.push_back(s[i]); i++; flag=1;
            }
            if(flag) words.push_back(temp);
        }
        for(int i=words.size()-1; i>=0; i--){
            res += words[i];
            if(i!=0) res.push_back(' ');
        }
        return res;
    }
};