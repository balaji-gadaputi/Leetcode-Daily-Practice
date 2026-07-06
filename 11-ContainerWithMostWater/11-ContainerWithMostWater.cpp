// Last updated: 06/07/2026, 12:01:18
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=-1,i=0,j=height.size()-1;
        while(i<j){
            int res;
            res=min(height[i],height[j])*abs(i-j);
            max=max>res?max:res;
            if(height[i]>height[j]){j--;}
            else{i++;}
        }
        return max;
    }
};