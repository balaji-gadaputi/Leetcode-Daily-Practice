// Last updated: 06/07/2026, 11:58:05
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int value,index=-1,min = INT_MAX;
        for(int i=0; i<capacity.size(); i++){
            if(capacity[i] >= itemSize){
                value = capacity[i]; 
                if(min > value){ min = value; index = i;}
            }
        }
        return index;
    }
};