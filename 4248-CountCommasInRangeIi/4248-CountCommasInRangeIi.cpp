// Last updated: 06/07/2026, 11:58:04
class Solution {
public:
    long long countCommas(long long n) {
        long long base = 1000;
        long long res = 0;
        if(n <= 999) return 0;
        while(base <= n){
            res += (n-base+1);
            base *= 1000;
        }
        return res;
    }
};