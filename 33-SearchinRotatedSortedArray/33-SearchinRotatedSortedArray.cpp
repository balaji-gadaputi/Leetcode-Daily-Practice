// Last updated: 14/03/2026, 14:06:38
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0, high = nums.size()-1;
5        while(low<=high){
6            int mid = low + (high-low)/2;
7            if(nums[mid] == target) return mid;
8            else if(nums[low]<=nums[mid]){ // left half is sorted
9                if(target<nums[mid] && target>=nums[low]) high = mid-1;
10                else low = mid+1;
11            }
12            else{ // right half is sorted
13                if(target>nums[mid] && target<=nums[high]) low = mid+1;
14                else high = mid-1;
15            }
16        }
17        return -1;
18    }
19};