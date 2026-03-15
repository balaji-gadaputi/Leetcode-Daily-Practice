// Last updated: 15/03/2026, 08:37:35
1class Solution {
2public:
3    int countCommas(int n) {
4        long long base = 1000;
5        long long res = 0;
6        if(n<=999) return 0;
7        while(base <= n){
8            res += (n-base + 1);
9            base *= 1000;
10        }
11        return res;
12    }
13};// commas increase at the rate of 10^3