// Last updated: 06/07/2026, 11:58:30
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        /*
        costs & Capacity [n] = i th machine
        budget
        select two machines such that cost < budget & max(capacity)
        */
        vector<pair<int,int>> tab;
        for(int i=0;i<costs.size(); i++){
            tab.push_back({costs[i],capacity[i]});
        }
        sort(tab.begin(), tab.end(), [](const auto &a,const auto &b){
            return a.first<b.first;
        });
        vector<int> prefix(costs.size()); prefix[0] = tab[0].second;
        for(int i=1; i<costs.size(); i++){
            prefix[i] = max(prefix[i-1], tab[i].second);
        }
        int ans = 0;
        for(int i=0; i<costs.size(); i++){
            if(tab[i].first < budget){
                ans = max(tab[i].second, ans);
            }
            int rem = budget - tab[i].first - 1;
            if(rem < 0) continue;
            int l = 0, r=i-1, pos = -1;
            while (l<=r){
                int m = (l+r)/2;
                if(tab[m].first <= rem){
                    pos = m; l = m+1;
                }else{
                    r = m-1;
                }
            }
            if(pos != -1){
                ans = max(ans, tab[i].second + prefix[pos]);
            }
        }
        return ans;
    }
};