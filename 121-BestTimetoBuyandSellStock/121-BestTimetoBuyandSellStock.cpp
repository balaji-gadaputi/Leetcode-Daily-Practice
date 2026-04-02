// Last updated: 02/04/2026, 19:05:37
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int minprice = prices[0], maxprofit = 0;
5        for(int i=1; i<prices.size(); i++){
6            if(minprice>prices[i]){
7                minprice = prices[i];
8            }
9            else{
10                int profit=prices[i] - minprice;
11                maxprofit = max(maxprofit,profit);
12            }
13        }
14        return maxprofit;
15    }
16};