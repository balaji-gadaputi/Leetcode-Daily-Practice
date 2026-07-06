// Last updated: 06/07/2026, 11:58:59
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
       int n=nums.size();
       int right=n-1, left=0,pos=n-1;
       while(left<=right){
           int rsq=nums[right]*nums[right];
           int lsq=nums[left]*nums[left];
           if(lsq>rsq){
               result[pos--]=lsq;left++;
           }
           else{
               result[pos--]=rsq;right--;
           }
       }
       return result;
    }
};