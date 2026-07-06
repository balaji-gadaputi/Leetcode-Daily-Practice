// Last updated: 06/07/2026, 12:00:52
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),area=0;
        vector<int> suffix( n,height[n-1] ), prefix( n,height[0] );
        for(int i=1; i<n; i++){
            prefix[i] = max( prefix[i-1],height[i] );
        }
        for(int i=n-1; i>0; i--){
            suffix[i-1] = max( suffix[i],height[i-1] );
        }
        for(int i=0; i<n; i++){
            area += min(suffix[i], prefix[i]) - height[i];
        }
        return area;
    }
};