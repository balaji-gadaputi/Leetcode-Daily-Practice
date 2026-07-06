// Last updated: 06/07/2026, 11:58:18
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<bool> bulb(101,false);
        vector<int> res;
        for(int i=0; i<n; i++){
            if(!bulb[ bulbs[i] ]){
                bulb[ bulbs[i] ] = true;
            }else{
                 bulb[ bulbs[i] ] = false;  
            }
        }
        for(int i=0; i<101; i++){
            if( bulb[i] ) res.push_back(i);
        }
        return res;
    }
}; // return the bulbs that are ON