// Last updated: 06/07/2026, 11:59:01
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,
            r=*max_element(piles.begin(),piles.end());
        
        while(l<r){
            int mid = l+(r-l)/2;
            int t = time(piles,mid);
            if(t>h) l = mid+1;
            else r = mid;
        }
        return l;
    }
    int time(vector<int> &piles, int x){
        int totalTime = 0;
        for(auto i:piles){
            totalTime += (i+x-1)/x;
        }
        return totalTime;
    }
};