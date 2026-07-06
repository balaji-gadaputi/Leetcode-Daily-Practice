// Last updated: 06/07/2026, 11:58:00
class Solution {
public:
    int maxDistance(string moves) {
        int res=0, f=0;
        unordered_map<char,char> mp = {
            {'U','D'},
            {'L','R'},
            {'D','U'},
            {'R','L'},
        };
        unordered_multiset<char> ms;
        for(auto i:moves){
            if( ms.find(i) != ms.end() ){ // complement found
                res--;
                ms.erase( ms.find(i) );
            }
            else{
                if(i == '_'){ f++; continue;}
                res++;
                ms.insert(mp[i]);
            }
        }
        return res+f;
    }
};