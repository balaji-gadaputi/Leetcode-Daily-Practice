// Last updated: 06/07/2026, 12:01:23
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size(), m = nums2.size(), total = n+m;
        int low = 0, high = n, half = (total+1)/2;

        while(low <= high){

            int i = low + (high-low)/2;
            int j = half - i;

            int aleft  = (i > 0) ? nums1[i-1] : INT_MIN;
            int aright = (i < n) ? nums1[i]   : INT_MAX;
            int bleft  = (j > 0) ? nums2[j-1] : INT_MIN;
            int bright = (j < m) ? nums2[j]   : INT_MAX;

            if( max(aleft, bleft) <= min(aright, bright) ){
                if(total %2 == 1) return max(aleft,bleft);
                else return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if(aleft>bright) high = i-1;
            else low = i+1;
        }
        return 0;
    }
};