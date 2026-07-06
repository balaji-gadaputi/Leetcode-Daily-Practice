// Last updated: 06/07/2026, 11:58:28
class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<32>(n).to_string();
        s.erase(0,s.find_first_not_of('0'));
        string rev = s;

        reverse(rev.begin(),rev.end());
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(rev[i] != s[i]){
                count++;
            }
        }
        return count;
    }
};