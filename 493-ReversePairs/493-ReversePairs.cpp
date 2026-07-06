// Last updated: 06/07/2026, 11:59:08
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(),count = 0;
        merge_sort(nums,0,n-1,count);
        return count;
    }
    void merge_sort(vector<int> &nums,int low, int high,int &count){
        if(high>low){
            int mid = (low + high)/2;
            merge_sort(nums,low,mid,count);
            merge_sort(nums, (mid+1),high,count);
            count = count + merge(nums,low,mid,high);
        }
    }
    int merge(vector<int> &nums,int low,int mid,int high){
        vector<int> lvec,rvec,temp;
        int i=low,j=mid+1,count=0;
        for(i=low;i<=mid;i++){
            while( (j<=high) && (long long)nums[i] > 2LL * nums[j] ){
                j++;
            }
            count += j-(mid+1);
        }

        i=low,j=(mid+1);

        while( i<=mid && j<=high ){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=high){
            temp.push_back(nums[j++]);
        }
        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
        return count;
    }
};