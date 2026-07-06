// Last updated: 06/07/2026, 11:59:26
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1 && citations[0] == 0) return 0;
        if(citations.size() == 1) return 1;
        int flag=1,x=1,largest=0;
        for(auto i:citations){
            if(i<=citations.size()){ flag=0; break; }
        } if(flag) return citations.size();

        sort(citations.begin(),citations.end(),greater<int>());
        for(auto i:citations){
            if(i >= x) largest = x;
            x++;
        }
        return largest;

    }
};