// Last updated: 23/03/2026, 10:53:46
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        
5        if (nums1.size() > nums2.size())
6            return findMedianSortedArrays(nums2, nums1);
7
8        int n = nums1.size(), m = nums2.size(), total = n+m;
9        int low = 0, high = n, half = (total+1)/2;
10
11        while(low <= high){
12
13            int i = low + (high-low)/2;
14            int j = half - i;
15
16            int aleft  = (i > 0) ? nums1[i-1] : INT_MIN;
17            int aright = (i < n) ? nums1[i]   : INT_MAX;
18            int bleft  = (j > 0) ? nums2[j-1] : INT_MIN;
19            int bright = (j < m) ? nums2[j]   : INT_MAX;
20
21            if( max(aleft, bleft) <= min(aright, bright) ){
22                if(total %2 == 1) return max(aleft,bleft);
23                else return (max(aleft, bleft) + min(aright, bright)) / 2.0;
24            }
25            else if(aleft>bright) high = i-1;
26            else low = i+1;
27        }
28        return 0;
29    }
30};