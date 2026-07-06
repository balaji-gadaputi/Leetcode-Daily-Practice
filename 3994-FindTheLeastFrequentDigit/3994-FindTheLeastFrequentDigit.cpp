// Last updated: 06/07/2026, 11:58:35
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        if(n==0) return 0;
        vector<int> res; unordered_map<int,int> m;
        while(n!=0){
            int dig = n%10;
            n = n/10; m[dig]++; 
        }
        int least = INT_MAX,leastKey;
        for(auto &p : m){
            if(p.second < least || (p.second == least && p.first < leastKey)) least = p.second, leastKey = p.first;
        }
        return leastKey;
    }
};

// If same frequency then return the smallest number