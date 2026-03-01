// Last updated: 01/03/2026, 08:26:05
1class Solution {
2public:
3    string trimTrailingVowels(string s) {
4        int n = s.length(); int i;
5        for(i = n-1; i>=0; i--){
6            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
7                continue;
8            } else break;
9        }
10        return s.substr(0,i+1);
11    }
12};