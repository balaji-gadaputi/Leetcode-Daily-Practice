// Last updated: 06/07/2026, 11:58:25
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ele;
        for(int i=0; i<n; i++){ // Retrieving positive elements
            if(nums[i]>=0){
                ele.push_back(nums[i]);
            }
        }
        if(ele.empty()) return nums;
        int m = ele.size(); k = k%m;
        vector<int> rotated(m);
        for(int i=0;i<m;i++){
            rotated[i] = ele[ (i+k)%m ];
        }
        
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                nums[i] = rotated[j++];
            }
        }
        return nums;
    }
};