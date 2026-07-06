// Last updated: 06/07/2026, 11:59:23
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> aux = nums;
        sort(aux.begin(),aux.end());
        for(int i=0;i<n-1;i++){
            if(aux[i]==aux[i+1]){
                return aux[i];
            }
        }
        return 0;
    }
};