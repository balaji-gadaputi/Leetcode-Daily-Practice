// Last updated: 06/07/2026, 12:00:05
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){
            int prev = i-1;
            if(ratings[i]>ratings[prev]){
                candies[i] = candies[prev] + 1;
            }
        }
        for(int i=ratings.size()-2; i>=0; i--){
            int next = i+1;
            if(ratings[i]>ratings[next]){
                candies[i] = max(candies[next]+1,candies[i]);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};