// Last updated: 06/07/2026, 12:00:11
class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for(auto i:s){
            if(isalnum(i)){
                clean.push_back(i);
            }
        }
        transform(clean.begin(),clean.end(),clean.begin(),[](char c){
            return tolower(c);
        });
        int left = 0, right = clean.size()-1;
        while(right>left){
            if(clean[right] != clean[left]){
                return false;
            }
            right--;left++;
        }
        return true;
    }
};