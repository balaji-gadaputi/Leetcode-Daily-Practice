// Last updated: 06/07/2026, 11:58:07
class Solution {
public:
    int countCommas(int n) {
        long long base = 1000;
        long long res = 0;
        if(n<=999) return 0;
        while(base <= n){
            res += (n-base + 1);
            base *= 1000;
        }
        return res;
    }
};// commas increase at the rate of 10^3