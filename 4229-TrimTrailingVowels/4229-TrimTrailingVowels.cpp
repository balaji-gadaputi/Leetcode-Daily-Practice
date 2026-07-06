// Last updated: 06/07/2026, 11:58:12
class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.length(); int i;
        for(i = n-1; i>=0; i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                continue;
            } else break;
        }
        return s.substr(0,i+1);
    }
};