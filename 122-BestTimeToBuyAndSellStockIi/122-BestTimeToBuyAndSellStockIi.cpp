// Last updated: 06/07/2026, 12:00:12
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a=0,b=1,profit=0;
        while(b < prices.size() ){
            if (prices[a] < prices[b]){
                profit += (prices[b] - prices[a]); a=b;
            }
            else {a = b;}
            b++;
        }
        return profit;
    }
};