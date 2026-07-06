// Last updated: 06/07/2026, 11:58:23
class Solution {
public:
    int vowelConsonantScore(string s) {
        /* 
        s = lowercase with letters & space, Digits
        v = No. of vowels c = No. of consonants
        if c>0 => score = floor(v/c) else floor = 0
        */
        string vowels = "aeiou";
        int v=0,c=0;
        for(int i=0; i<s.length(); i++){
            if( (bool)isalpha(s[i]) ){
                if(vowels.find(s[i]) == string::npos){ // consonant
                    c++;
                }else v++; // vowel
            }
        }
        if(c>0) return (floor(v/c));
        else return 0;
    }
};