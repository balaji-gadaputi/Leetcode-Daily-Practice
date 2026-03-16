// Last updated: 16/03/2026, 12:41:27
1class MyStack {
2public:
3    queue<int> q1; queue<int> q2;
4    MyStack() {
5
6    }
7    // push & pop must be in the front only
8    void push(int x) {
9        q2.push(x);
10        while(!q1.empty()){
11            q2.push(q1.front());
12            q1.pop();
13        }
14        while(!q2.empty()){
15            q1.push(q2.front());
16            q2.pop();
17        }
18    }
19    
20    int pop() {
21        if(q1.empty()) return NULL;
22        int val = q1.front();
23        q1.pop(); return val;
24    }
25    
26    int top() {
27        if(q1.empty()) return NULL;
28        return q1.front();
29    }
30    
31    bool empty() {
32        return q1.empty();
33    }
34};
35
36/**
37 * Your MyStack object will be instantiated and called as such:
38 * MyStack* obj = new MyStack();
39 * obj->push(x);
40 * int param_2 = obj->pop();
41 * int param_3 = obj->top();
42 * bool param_4 = obj->empty();
43 */