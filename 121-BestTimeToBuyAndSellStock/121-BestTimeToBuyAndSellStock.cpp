// Last updated: 06/07/2026, 12:00:14
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0], maxprofit = 0;
        for(int i=1; i<prices.size(); i++){
            if(minprice>prices[i]){
                minprice = prices[i];
            }
            else{
                int profit=prices[i] - minprice;
                maxprofit = max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};