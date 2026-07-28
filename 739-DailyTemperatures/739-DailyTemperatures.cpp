// Last updated: 28/07/2026, 12:26:00
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        stack<int> st; vector<int> res(temperatures.size(),0);
5        for(int i=temperatures.size()-1; i>-1; i--){
6            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
7            if(!st.empty()) res[i] = st.top()-i;
8            st.push(i);
9        }
10        
11        return res;
12    }
13    // find a when does the next greater element occur
14    // So i guess the difference in the index would work 
15};