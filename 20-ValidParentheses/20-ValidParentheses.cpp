// Last updated: 16/03/2026, 13:06:35
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        for(auto i:s){
6            if(i == '(') st.push(')');
7            else if(i == '{') st.push('}');
8            else if(i == '[') st.push(']');
9            else{
10                if(!st.empty() && st.top() == i) st.pop();
11                else return false;
12            }
13        }
14        if(st.empty()) return true;
15        else return false;
16    }
17};