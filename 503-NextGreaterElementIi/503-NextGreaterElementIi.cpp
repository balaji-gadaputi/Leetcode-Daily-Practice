// Last updated: 15/07/2026, 10:38:42
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size()); stack<int> st;
        int n = nums.size();
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            if(i<n){
                if(st.empty()) res[i] = -1;
                else res[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};