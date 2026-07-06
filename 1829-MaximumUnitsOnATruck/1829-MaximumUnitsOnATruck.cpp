// Last updated: 06/07/2026, 11:58:50
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Maximum Units
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a, vector<int>&b){
            return a[1]>b[1];
        });
        int profit=0, n=boxTypes.size(), w=truckSize;
        for(int i=0; i<n; i++){
            if (w<=0) break;
            if(boxTypes[i][0]<= w){
                profit += boxTypes[i][0] * boxTypes[i][1];
                w=w-boxTypes[i][0];
            }
            else{
                profit += w*boxTypes[i][1];
                w=w-w;
            }
        }
        return profit;
    }
};