// Last updated: 06/07/2026, 12:00:25
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m; int index=0;
        for(int i=0; i<nums.size(); i++){
            if( m.find(nums[i]) == m.end() ){
                m[nums[i]]=1;
                nums[index]=nums[i]; index++;
            }
            else{
                if( m[ nums[i] ] < 2 ){
                    m[nums[i]]++;
                    nums[index]=nums[i]; index++;
                }
            }
        }
        return index;
    }
};