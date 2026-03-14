// Last updated: 14/03/2026, 13:40:17
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int pivot=(0+((nums.size()-1)-0)/2);
5        if(nums.size() == 1 && nums[0] != target) return -1;
6        else if(nums.size() == 1 && nums[0] == target) return 0;
7
8        for(int i=0; i<nums.size()-1; i++){
9            if(nums[i] > nums[i+1]){
10                pivot = i+1;
11            }
12        }
13        int low = 0, high = pivot-1;
14        while(low<=high){
15            int mid = low + (high-low)/2;
16            if(nums[mid] == target) return mid;
17            else if(nums[mid] > target) high = mid-1;
18            else low = mid+1;
19        }
20        low = pivot; high = nums.size()-1;
21        while(low<=high){
22            int mid = low + (high-low)/2;
23            if(nums[mid] == target) return mid;
24            else if(nums[mid] > target) high = mid-1;
25            else low = mid+1;
26        }
27        return -1;
28    }
29};