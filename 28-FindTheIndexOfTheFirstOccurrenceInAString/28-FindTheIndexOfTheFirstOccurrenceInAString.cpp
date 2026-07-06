// Last updated: 06/07/2026, 12:01:00
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++){
            int j=0; while( haystack[i+j]==needle[j] && j<needle.size() )
            { j++; } if( j == needle.size() ) return i; 
        }
        return -1;
    }
};